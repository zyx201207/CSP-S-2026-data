#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=2e6+5;
struct Node{
	ll v,w;
};
bool operator<(const Node &a,const Node &b){
	return a.w>b.w;
}
ll n,d,a[ma],dis[ma],cnt[ma];
bool vis[ma];
void dfs(int idx,int stp){
	if(stp<dis[idx]){
		cnt[idx]=1;
		dis[idx]=stp;
	}else if(stp==dis[idx]){
		cnt[idx]++;
	}else{
		return;
	}
	for(int i=idx+1;i<=n;i++){
		if(abs(a[idx]-a[i])<=d){
			dfs(i,stp+1);
		}else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			dfs(i,0);
			for(int j=1;j<=n;j++){
//				cout<<dis[j]<<" ";
				if(cnt[j]==2)ans++;
			}
//			cout<<'\n';
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
*/
