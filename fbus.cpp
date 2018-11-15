//#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class reservation

{

  char bus_number[5], driver_name[10], arrival[5],departure[5], from[10], to[10], seats[8][4][10];

public:

  void install();

  void allotment();

  void empty();

  void show();

  void availability();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void reservation::install()

{

  cout<<"Enter bus no: ";

  cin>>bus[p].bus_number;

  cout<<"\nEnter driver_name's name: ";

  cin>>bus[p].driver_name;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\ndeparture: ";

  cin>>bus[p].departure;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].to;

  bus[p].empty();

  p++;

}

void reservation::allotment()

{

  int seats;

  char number[5];

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].bus_number, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nseats Number: ";

    cin>>seats;

    if(seats>32)

    {

      cout<<"\nThere are only 32 seatss availabilityable in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seats[seats/4][(seats%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seats[seats/4][(seats%4)-1];

        break;

      }

    else

      cout<<"The seats no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }


void reservation::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seats[i][j], "Empty");

    }

  }

}

void reservation::show()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].bus_number, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus no: \t"<<bus[n].bus_number

  <<"\ndriver_name: \t"<<bus[n].driver_name<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tdeparture time:"<<bus[n].departure

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seats[i][j],"Empty")!=0)

      cout<<"\nThe seats no "<<(a-1)<<" is reserved for "<<bus[n].seats[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}

void reservation::position(int l)

{

  int s=0;
  int q=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seats[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seats[i][j];

          q++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seats[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<q<<" seatss empty in Bus No: "<<bus[l].bus_number;

  }

void reservation::availability()

{

  cout<<"p"<<p<<"\n";
  for(int n=0;n<p;n++)
  
  {
    cout<<"n"<<n;
    vline('*');

    cout<<"Bus no: \t"<<bus[n].bus_number<<"\ndriver_name: \t"<<bus[n].driver_name

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tdeparture Time: \t"

    <<bus[n].departure<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}

int main()

{

system("cls");

int c;

while(1)

{

    //system("cls");

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Install\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.Show\n\t\t\t"

  <<"4.Buses availability. \n\t\t\t"

  <<"5.Exit";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>c;

  switch(c)

  {

    case 1:  bus[p].install();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].availability();

      break;

    case 5:  exit(0);

  }

}

return 0;

}

