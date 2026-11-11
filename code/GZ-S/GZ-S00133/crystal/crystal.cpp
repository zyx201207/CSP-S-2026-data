//贵州省遵义市新蓝学校   王冰洁   GZ-S00133
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	int n,m;
	cin>>n>>m;
	int a[n]={0};
	for(int i=0; i<=n-1; i++)
	{
		cin>>a[i];	
	}
	
	int d=a[1]-a[0];
	int x=0;
	int cnt=1;
	
	for(int j=1; j<=n; j++)
	{
		if(m<x+d)
		{
			break;
		}
		if( (m>x+d) && (m<2*(x+d)) )
		{
			cnt++;
			break;
		}
		x=x+d;
		m=m-2*x;
		cnt=cnt+2;
	}
	
	cout<<cnt;
	freopen("crystal.out","w",stdout);
	
	return 0;
} 
