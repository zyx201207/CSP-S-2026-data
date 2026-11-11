#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[200005];
vector<long long> G[1005];
bool vis[200005];
long long minn=1e9,cnt;
void dfs(int now,int tar,long long p){
	if(now==tar){
		if(p<minn){
			minn=p;
			cnt=1;
		}else if(p==minn){
			cnt++;
		}
		return;
	}
	for(int i=0;i<G[now].size();i++){
		int nxt=G[now][i];
		if(vis[nxt]==0){
			vis[nxt]=1;
			dfs(nxt,tar,p+1);
			vis[nxt]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			while(G[i].size()) G[i].pop_back();
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof vis);
				minn=1e18;
				cnt=0;
				vis[i]=1;
				dfs(i,j,0ll);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
