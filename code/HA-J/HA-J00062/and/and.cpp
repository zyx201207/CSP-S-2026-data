#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,a[N],maxn,v[N];
bool vis[N];
void dfs(int dep){
	if(dep==m){
		int cnt=2147483647;
		for(int i=0;i<dep;i++){
			cnt&=v[i];
		}
		maxn=max(maxn,cnt);
		return;
	}
	for(int i=1;i<=n&&!vis[i];i++){
		v[dep]=a[i];
		vis[i]=1;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
	cout<<maxn<<'\n';
	return 0;
}
/*
5 3
31 3 1 15 7

*/
