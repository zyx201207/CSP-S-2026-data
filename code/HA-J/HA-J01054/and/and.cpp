#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e5+5;
ll n,m,maxx,a[M];
void dfs(ll dep,ll g,ll h){
	if(g==m){
		maxx=max(maxx,h);
		return ;
	}
	if(dep==n+1) return ;
	dfs(dep+1,g,h);
	if(h==-1){
		dfs(dep+1,g+1,a[dep]);
	}else{
		dfs(dep+1,g+1,h&a[dep]);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		dfs(1,0,-1);
	cout<<maxx;
	return 0;
} 

