#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int maxn=INT_MIN;
int a[200009];
void dfs(int x,int y,int z)
{
	if(x>n+1)
	{
		if(z>maxn)maxn=z;
		return;
	}	
	if(y>=m)
	{
		if(z>maxn)maxn=z;
		return;
	}
	if(n-x+1+y<m)return;
	dfs(x+1,y+1,z&a[x]);
	dfs(x+1,y,z);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,2147483647);
	cout<<maxn;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
