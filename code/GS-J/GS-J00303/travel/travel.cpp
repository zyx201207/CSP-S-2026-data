#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sx,sy;
	char cx[4],cy[4];
	cin>>sx;
	for(int i=1;i<=3;i++)
	{
		cin>>cx[i];
	}
	cin>>sy;
	for(int i=1;i<=3;i++)
	{
		cin>>cy[i];
	}
	int a=cx[1]-'0',b=cy[1]-'0',c=cx[2]-'0',d=cy[2]-'0';
	int e=cx[3]-'A',f=cy[3]-'A';
	if(sx==sy)
	{
		cout<<"1";
		if(a*10+c==b*10+d)
	    {
		    cout<<"1";
		if(e==0||e==1||e==2)
		{
			if(f==0||f==1||f==2) 
			{
				cout<<"1";
				if(e-f==1||f-e==1)
	            {
		            cout<<"1";
	            }
	            else cout<<"0";
			}
			else cout<<"00";
		}
		else
		{
			if(f==3||f==4) 
			{
				cout<<"1";
				if(e-f==1||f-e==1)
	            {
		            cout<<"1";
	            }
	            else cout<<"0";
			}
			else cout<<"00";
		}
		
	    }
	    else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}
