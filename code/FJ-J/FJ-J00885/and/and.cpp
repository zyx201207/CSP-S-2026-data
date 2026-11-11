#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int f[1010],a[1010];
int n,m;
int ans;
void check(int a,int b){
	ans=max(ans,a&b);
	//cout<<a<<" "<<b<<" "<<(a&b)<<" "<<ans<<endl;
	return;
}
bool vis[1010];
void dfs(int x){
	if(x>m){
		for(int i=1;i<=m;i++){
			if(f[i]!=f[i-1]) check(a[f[i]],a[f[i-1]]);
			//cout<<f[i]<<" ";
		}
		//cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		f[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

