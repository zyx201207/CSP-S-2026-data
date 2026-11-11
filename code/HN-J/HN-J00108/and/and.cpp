#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],vis[200005],maxx=0;
void dfs(int x,int y){
	if(x>n||y>m){
		for(int i=2;i<=y;i++){
			vis[i]=(vis[i]&vis[i-1]);
		}
		maxx=max(maxx,vis[m]);
		y=1;
		return ;
	}
	dfs(x+1,y);
	
	vis[y]=a[x];
	dfs(x+1,y+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	cout<<maxx;
	return 0;
}
