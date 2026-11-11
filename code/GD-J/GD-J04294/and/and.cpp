#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,maxn,a[200005];
void dfs(ll c,ll b,ll d)
{

	if(b>m)return;
	if(c>n)return;
	if(b==m)maxn=max(maxn,d);
	if(b==0)dfs(c+1,b+1,a[c+1]&a[c+1]);
		dfs(c+1,b+1,d&(a[c+1]));
	dfs(c+1,b,d);
}
int main()
{
	
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	freopen("and.in","r",stdin);
	dfs(1,1,a[1]&a[1]);
	dfs(1,0,0);
	cout<<maxn<<endl;
	
}
