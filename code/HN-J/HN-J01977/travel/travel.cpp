#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[5],b[5],z[5],x[5];
	cin>>a[0]>>a[1];
	cin>>z[0]>>z[1]>>z[2];
	cin>>b[0]>>b[1];
	cin>>x[0]>>x[1]>>x[2];
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<1;
		if(z[0]==x[0]&&z[1]==x[1])
		{
			cout<<1;
			if(z[2]=='D'||z[2]=='F')
			{
				if(x[2]=='D'||x[2]=='F')
					cout<<"11";
			}
			else if(z[2]=='A'||z[2]=='B'||z[2]=='C')
			{
				if(x[2]=='A'||x[2]=='B'||x[2]=='C')
				{
					cout<<"1";
					if(z[2]=='A')
					{
						if(x[2]=='B')
							cout<<"1";
						else cout<<'0';
					}
					else if(z[2]=='B')
					{
						cout<<"1";
					}
					else if(z[2]=='C')
					{
						if(x[2]=='B')
						cout<<1;
						else cout<<0;
					}
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else 
	cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
