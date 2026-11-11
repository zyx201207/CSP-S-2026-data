#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,m,a[N],ans=INT_MIN;
bool f[N];
void dfs(int sum,int x)
{
	if(x==m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]) continue;
		f[i]=1;
		dfs(sum&a[i],x+1);
		f[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		dfs(a[i],1);
		f[i]=0;
	}
	cout<<ans;
	return 0;
} 
