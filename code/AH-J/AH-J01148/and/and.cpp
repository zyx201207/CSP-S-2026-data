#include<bits/stdc++.h>
using namespace std;
long long n,m,f[200005],ans=-1;
long long a[200005];
void dfs(long long x,long long t,long long sum)
{
	long long p=sum;
	if(t==m) 
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			sum=sum&a[x];
			dfs(i,t+1,sum);
			sum=p;
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		dfs(i,0,a[i]);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
