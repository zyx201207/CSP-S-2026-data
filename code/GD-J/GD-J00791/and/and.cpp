#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200005];
ll maxx=-100;
bool vis[105];
ll b[20005];
void dfs(int cnt){
	if(cnt==m){
		ll ans=b[1];
		for(int i=2;i<=m;i++){
			ans&=b[i];
		}
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			cnt++;
			b[cnt]=a[i];
			vis[i]=1;
			dfs(cnt);
			vis[i]=0;
			cnt--;
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==1){
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
		}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	else if(n<=20){
		dfs(0);
		cout<<maxx;
	}
	else {
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
