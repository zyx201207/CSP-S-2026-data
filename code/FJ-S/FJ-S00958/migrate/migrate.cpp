#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e6;
long long x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<n;j++) cin>>x;
	}
	if(x%2==0)
	{
		cout<<0<<endl;
	}
	return 0;
}
