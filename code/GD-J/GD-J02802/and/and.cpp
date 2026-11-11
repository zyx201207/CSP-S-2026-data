#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],m,ans,mx;
vector<int> g[N];
void dfs(int x,int t,int cnt){
	if(x==n+1) return ;
	if(cnt==m){
		ans=max(ans,t);
		return ;
	}
	dfs(x+1,(t&a[x]),cnt+1);
	dfs(x+1,t,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n-1;i++) ans=ans&(a[i]&a[i+1]);
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	dfs(1,a[1],1);
	cout<<ans;
	return 0;
}
