#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int n,m;
int maxS=-1;
void dfs(int x,int t,int sum){
	if(x>n){
		if(t<m) return;
		maxS=max(maxS,sum);
		return;
	}
	if(t==m){
		maxS=max(maxS,sum);
		return;
	}
	//if true:
	if(t<m) dfs(x+1,t+1,sum&a[x]);
	//if false:
	dfs(x+1,t,sum);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<maxS;
	
	return 0;
}
