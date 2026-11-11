#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,m;
int a[N];
int ans;
bool vis[N];
void solve(){
	memset(vis,1,sizeof(vis));
	
	for(int i=30;i>=0;i--){
		int num=0;
		for(int j=1;j<=n;j++)if(vis[j]){
			if(a[j]&(1<<i))num++;
		}
		if(num>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++)if(vis[j]){
				if(!(a[j]&(1<<i)))vis[j]=0;
			}
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	solve();
	
	cout<<ans<<'\n';
	
	return 0;
}
