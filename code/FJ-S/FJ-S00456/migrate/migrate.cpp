#include<bits/stdc++.h>
using namespace std;
long long c,t;
int func(int x)
{
	if(x==1||x==2) return 1;
	if(x==3||x==4) return 2;
	return func(x-1)+func(x-2);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,d;
		long long a[10010];
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>a[i];
		cout<<func(a[n/2])<<endl;
	}
}
