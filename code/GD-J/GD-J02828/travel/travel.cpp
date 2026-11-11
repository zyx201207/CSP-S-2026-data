#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	if(n==m)
	{
		if(x[0]==y[0]&&x[1]==y[1])
		{
			if((x[2]<='C'&&y[2]<='C')||(x[2]>='D'&&y[2]>='D'))
			{
				int a=int(x[2]),b=int(y[2]);
				if(a+1==b||a-1==b)cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
 } 
