#include<iostream>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a[0] == c[0] && a[1] == c[1])
	{
		cout << 1;
		if(b[0] == d[0] && b[1] == d[1])
		{
			cout << 1;
			char w = b[2];
			char x = d[2];
			if((w>='A' && w<='C' && x>='A' && x<='C') || (w=='D' && x=='F' || w=='F' && x=='D'))
			{
				cout << 1;	
				bool flag = 0;
				for(char i = 'A';i <= 'F';i ++)
				{
					if(w == 'C' && x == 'D' || w == 'D' && x == 'C')
					{
						flag = 0;
					}
					if(w == i && (x == i+1 || x == i-1))
					{
						flag = 1;
					}
				}
				cout << flag;
			}
			else
			{
				cout << "00";
			} 
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}	
} 

