#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int z=2e5+9;
int n,m,maxx=INT_MIN;
int a[z];
void dfs(int step,int dis,int sx)
{
	if(step>m)
	{
		maxx=max(maxx,dis);
		return ;
	}
	if(n-sx+1+step<m) return ;
	dfs(step+1,dis&a[sx],sx+1);
	dfs(step,dis,sx+1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	dfs(1,LLONG_MAX,1);
	cout<<maxx;
	return 0;
}
/*

*/

