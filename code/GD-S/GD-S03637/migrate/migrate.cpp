#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int n,d,ans;
int a[maxn];
vector<int> vec[maxn];
int cnt[maxn],dis[maxn];
const int inf=1e18;
void calc(int p){
	cnt[p]=1;
	for(int i=p;i<=n;i++) dis[i]=inf;
	dis[p]=0;
	for(int i=p;i<=n;i++){
		if(dis[i]>=inf||cnt[i]==0) continue;
		if(i!=p&&cnt[i]==2){
			ans++;
		}
		for(int j:vec[i]){
			if(dis[i]+1==dis[j]) cnt[j]+=cnt[i];
			else if(dis[i]+1<dis[j]){
				dis[j]=dis[i]+1;
				cnt[j]=cnt[i];
			}
		}
	}
	for(int i=p;i<=n;i++) dis[i]=0;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],vec[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				vec[i].push_back(j);
			}
			else break;
		}
	}
	ans=0;
	for(int i=1;i<=n;i++) calc(i);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 1
5 3
-2 -1 0 1 2
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
