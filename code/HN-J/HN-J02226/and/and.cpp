#include<bits/stdc++.h>
using namespace std;

int n,m,maxs = 0;
int a[200005];
void dfs(int x,int y,int c)
{
	if(c>=n && x<m) return;
	if(x==m) 
	{
	    maxs=max(maxs,y);
		return;
    }
	for(int i = c+1;i <= n;i++)
	{
		if(x==0)dfs(x+1,a[i],i);
		else dfs(x+1,(a[i]&y),i);
	}
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	dfs(0,0,1);
	cout << maxs;
}
