#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
vector<long long> a(200005);
bool vis[200005];
long long dfs(long long beg,long long x,int t){
	if(t==m) return x;
	for(int i=beg+1;i<n;i++){
		if(!vis[i]){
			vis[i]=true;
			ans=max(ans,dfs(i,x&a[i],t+1));
		}
		vis[i]=false;
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxa=-1;
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		cout<<maxa;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],0);
	}
	cout<<ans;
	return 0;
}
