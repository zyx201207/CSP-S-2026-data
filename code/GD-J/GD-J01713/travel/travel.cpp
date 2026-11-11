#include<iostream>
using namespace std;
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])
	{
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			if(int(b[2])>=68&&int(d[2])>=68)
			{
				cout<<"11";
			}
			else if(int(b[2])<=67&&int(d[2])<=67)
			{
				cout<<"1";
				if(int(b[2]+1)==int(d[2])||int(b[2]-1)==int(d[2]))
				{
					cout<<"1";
				}
				else
				{
					
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	} 
	else
	{
		cout<<"0000";
	}
} 
