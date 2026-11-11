#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+7;
int c,t;
long long x[MAXN]={0};
void solve()
{
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	long long b=x[2]-x[1];
	bool flag=0;
	for(int i=3;i<=n;i++)
	{
		if(x[i]-x[i-1]!=b)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		int cnt=0;
		if(d<x[3]-x[1]) cout<<0<<endl;
		else
		{
			long long a=d/(x[2]-x[1])+1;
			for(long long i=1;i+a<=n;i++) cnt++;
			cout<<cnt<<endl;
		}
	}
	else cout<<0<<endl;
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
 
