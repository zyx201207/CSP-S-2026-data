#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],f[N],s[N],t[N],tp,inv[N],tong[N];
void dfs(int x){
	if(x==n){
		ans[a[x]]++;
		return ;
	}
	if(inv[a[x]]==x){
		ans[a[x]]++;
		dfs(x+1);
	}
	else{
		dfs(inv[a[x]]);
	}
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=n;i>=1;i--){
		if(inv[a[i]]==0){
			inv[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
