#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n,m;
unsigned long long a[N],ma;
bool f[N];

unsigned long long dfs(int dep,int i)
{
	if(dep==0)return a[i];
	unsigned long long sum=0;
	
	for(;i<=n;++i)
	{
		if(!f[i])
		{
			f[i]=1;
			sum=a[i]&dfs(dep-1,i+1);
			f[i]=0;
		}
		
		if(dep==1)ma=max(ma,sum);
	}
	return sum;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	
	if(n==m)
	{
		ma=a[1];
		for(int i=2;i<=n;++i)ma=ma&a[i];
		cout<<ma<<'\n';
		return 0;
	}
	
	dfs(m,1);
	
	cout<<ma;
	return 0;
}
