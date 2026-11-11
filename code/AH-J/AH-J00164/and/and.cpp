#include <bits/stdc++.h>
using namespace std;
int a[200001];
int n,m,ans;
void dfs(int step,int pos,int an,int as)
{
	if(pos>n)return;
	if(step==m+1)
	{
		ans=an;
		return;
	}
	an=an&a[pos];
	if(an<=ans)return;
	dfs(step+1,pos+1,an,an);
	an=as;
	dfs(step,pos+1,an,an);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,1,(1<<30)-1,(1<<30)-1);
	cout<<ans;
	return 0;
}
