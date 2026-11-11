#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[200005];
long long a[200005],maxn;
void dfs(int x,long long s){
	if(x>m){
		maxn=max(maxn,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,s&a[i]);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1073741823);
	cout<<maxn;
	return 0;
}

