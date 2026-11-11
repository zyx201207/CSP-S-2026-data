#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cher,zuor,chex,zuox;
	int s;
	cin>>cher>>zuor>>chex>>zuox;
	if (cher==chex)
	{
		cout<<1;
		int a=(zuor[0]-'0')*10+(zuor[1]-'0');
		int b=(zuox[0]-'0')*10+(zuox[1]-'0');
		if (a==b)
		{
			cout<<1;
			if (((zuor[2]-'A')<3 &&(zuox[2]-'A')<3)  ||((zuor[2]-'A')>2 &&(zuox[2]-'A')>2) )
			{
				cout<<1;
				if ((zuor[2]-zuox[2] == 1) || (zuor[2]-zuox[2] == -1))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0;
				cout<<0;
			}
		}
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
}
