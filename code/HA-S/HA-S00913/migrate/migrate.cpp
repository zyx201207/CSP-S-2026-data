#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;

const int N = 2e6+10;

int c,t;
int n;
ll d;
ll ans;
ll a[N],dis[N];
ll cnt[N];
vector<int> e[N];
map<int,int> mp;
//vector<int> sd;

void init(){
	memset(a,0,sizeof(a));
	for(int i=0;i<=n+2;i++) e[i].clear();
}
//ll sum;
//void dfs(int u){
//	for(auto v : e[u]){
//		sum++;
//		if(dis[v]==sum){
//			cnt[v]++;
//			if(cnt[v]==1) ans++;
//			if(cnt[v]==2) ans--;
//		}
//		else if(dis[v]>sum){
//			cnt[v]=0;
//			dis[v]=sum;
//		}
//	cout<<sum<<" ";
//				cout<<u<<" "<<v<<" "<<dis[v]<<" "<<cnt[v]<<" "<<ans<<" "<<'\n';
//		 
//		dfs(v);
//		sum--;
//	}
//}

void dfs(int u){
	for(auto v : e[u]){
		
		if(dis[v]==dis[u]+1){
			cnt[v]++;
			if(cnt[v]==1) ans++,mp[v]++;
			if(cnt[v]==2) ans--,mp[v]--;
		}else{
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				if(cnt[v]==1) ans--,mp[v]--;
				cnt[v]=0;
			}	
		}

//		cout<<u<<" "<<v<<" "<<dis[v]<<" "<<cnt[v]<<" "<<ans<<" "<<'\n';
		
		dfs(v);
	}
}

void solve(){
	init();
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<'\n';

	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				e[i].push_back(j);
			}
		}
	}	
	
	ll tmp=0;
	for(int i=1;i<n;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		dis[i]=ans=0;

//		sum=0;
		dfs(i);
//		cout<<"#\n";
//		for(auto i : mp){
//			if(i.second!=0) cout<<i.first<<" ";
//		}
//		cout<<'\n';
//		cout<<"i_ans:"<<ans<<'\n';
		tmp+=ans;
	}
	cout<<tmp<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t-->0){
		solve();
	}
	return 0;
}
/*
1 1
10 3 
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

1 1
6 2
 1 2 3 4 6 8
*/
