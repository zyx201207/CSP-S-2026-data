#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,v,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>v;
	while(v--)
	{
		int n,m;
		cin>>n>>m;
		int x,y,flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i==1) x=a[i];
			else if(i==2) y=a[i]-a[i-1]; 
			else if(a[i]-a[i-1]!=y) flag=0;
		}
		if(flag==1)
		{
			if(m<y) cout<<0<<endl;
			int d=m/y;
			cout<<n-2*d+1>0?n-2*d+1:0<<endl;
		}
	}
	return 0;
}
