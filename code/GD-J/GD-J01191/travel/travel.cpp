#include<bits/stdc++.h>
using namespace std;
char a1,a2,b1,b2,x1,x2,y1,y2;
char c,d;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>x1>>x2>>c;
	cin>>b1>>b2>>y1>>y2>>d;
	if(a1==b1&&a2==b2)
	{
		cout<<1;
		if(x1==y1&&x2==y2)
		{
			cout<<1;
			if((c>='A'&&c<='C'&&d>='A'&&d<='C')||((c=='D'||c=='F')&&(d=='D'||d=='F')))
			{
				cout<<1;
				if(((c=='D'||c=='F')&&(d=='D'||d=='F'))||((c=='A'||c=='B')&&(d=='A'||d=='B'))||((c=='B'||c=='C')&&(d=='C'||d=='B')))
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
	
	return 0;
 } 
