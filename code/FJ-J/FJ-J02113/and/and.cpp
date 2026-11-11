#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int MAXN=200005;
int n,m;
int a[MAXN],p[MAXN];
int ans=0;
void dfs(int x,int y)
{
	if(x>=m)
	{
		int t=p[0];
		for(int i=1;i<x;i++)
		{
			t=t&p[i];
		}
		ans=max(ans,t);
		return;
	}
	for(int i=y+1;i<=n;i++)
	{
		p[x]=a[i];
		dfs(x+1,i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}
