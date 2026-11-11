#include<bits/stdc++.h>
using namespace std;
string x,y,x1,y1;
int f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>x1>>y1;
	if(x==x1)
	{
		f=1;
		if(y[0]==y1[0]&&y[1]==y1[1]) 
		{
			f=2;
			if((y[2]<='C'&&y1[2]<='C')||(y[2]>='D'&&y1[2]>='D'))
			{
				f=3;
				if(abs(y[2]-y1[2])==1) f=4;
			}
		}
	}
	if(f==0) cout<<"0000";
	if(f==1) cout<<"1000";
	if(f==2) cout<<"1100";
	if(f==3) cout<<"1110";
	if(f==4) cout<<"1111";
	
	return 0;
} 
