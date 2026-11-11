#include<bits/stdc++.h>
using namespace std;
int x[10005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[1]+x[i]+x[i+1]<x[1]+x[i]+x[i++])
		{
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
