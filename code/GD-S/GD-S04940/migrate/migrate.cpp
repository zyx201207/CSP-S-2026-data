#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1; i<=t; i++)
	{
		int n,m;
		cin>>n>>m;
		for(int j=1; j<=n; n++) cin>>x[j];
		if(x[3]-x[2]==x[2]-x[1] && x[4]-x[3]==x[2]-x[1]) cout<<n*n;
	}
	return 0;
	
}
