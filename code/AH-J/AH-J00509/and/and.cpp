#include <bits/stdc++.h>
using namespace std;
long long n,k,a[200005],b[200005],c[200005],t=-1;
void dfs(int u)
{
	if(u==k)
	{
		for(int i=2;i<=u;i++)b[i]&=b[i-1];
		if(t<b[u])t=b[u];
		return;
	}
	for(int i=1;i<=n;i++)if(c[i]==0)c[i]=1,b[++u]=a[i],dfs(u),u--,c[i]=0;
	return;
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
dfs(0);
cout<<t;
return 0;
}
