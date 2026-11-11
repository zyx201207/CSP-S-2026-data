#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	cin>>a>>b>>c>>d;
	int w=(b[0]-'0')*10+b[1]-'0',x=(d[0]-'0')*10+d[1]-'0';
	//cout<<w<<" "<<x<<endl;
	char y=b[2],z=d[2];
	if(a==c)
	{
		cout<<1;
		if(w==x)
		{
			cout<<1;
			if((y<='C'&&z<='C')||(y>='D'&&z>='D'))
			{
				cout<<1;
				if(abs(y-z)==1)
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
