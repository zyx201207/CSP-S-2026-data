#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,maxx=0;
int a[200005];
void dfs(int step,int dq,int t){
	if(t>m) return ;
	if(step>n){
		if(t==m){
			maxx=max(maxx,dq);
		}
		return ;
	}
	if(t==0){
		dfs(step+1,a[step],t+1);
	}
	else dfs(step+1,(dq & a[step]),t+1);
	dfs(step+1,dq,t);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}
