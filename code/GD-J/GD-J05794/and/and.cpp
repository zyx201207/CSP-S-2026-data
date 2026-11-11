#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,b[1000005];
void dfs(long long k,long long m)
{
	if(k>m)
	{
		long long s=a[b[1]];
		for(int i=1;i<=m;i++)
		{
			s=s&a[b[i]];
		}
		ans=max(ans,s);
		return;
	}
	for(int i=b[k-1]+1;i<=n;i++)
	{
		b[k]=i;
		dfs(k+1,m);
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
	dfs(1,m);
	cout<<ans;
	return 0;
} 
