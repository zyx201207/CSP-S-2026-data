#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,ans,a[maxn];
bool vis[maxn];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if((1<<j)&a[i])cnt++;
		}
		if(cnt<m)continue;
		ans+=1<<j;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(((1<<j)&a[i])==0)vis[i]=1;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)solve();
	return 0;
}
