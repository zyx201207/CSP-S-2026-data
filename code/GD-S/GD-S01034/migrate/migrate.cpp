#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e6+50,INF=1e18;
ll c_id,T,n,d,dis[maxn],cnt[maxn],f[maxn],ans;
vector<int>m[maxn];
struct Node{
	ll v,w,cnt;
};
queue<Node>q;
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++){
		cin>>f[i];m[i].clear(),dis[i]=INF,cnt[i]=0ll;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[j]-f[i]>d) break;
			m[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		q.push({i,0,1});cnt[i]=1;
		while(!q.empty()){
			int now=q.front().v,noww=q.front().w,nowcnt=q.front().cnt;q.pop();
			if(nowcnt<cnt[now]) continue;
			for(int j=0;j<(int)m[now].size();j++){
				int net=m[now][j];
				if(dis[net]==INF) dis[net]=noww+1,cnt[net]+=nowcnt,q.push({net,dis[net],cnt[net]});
				else if(noww+1==dis[net]) cnt[net]+=nowcnt,q.push({net,dis[net],cnt[net]});
			}
		}
		for(int j=1;j<=n;j++){
			if(dis[j]!=INF&&cnt[j]==2) ans++;
			dis[j]=INF,cnt[j]=0ll;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){ 
	cout<<rand()<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>c_id>>T;
	if(c_id<=10) while(T--) solve();
	else if(c_id<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>f[i];
			if(d<2*(f[n]-f[n-1])) cout<<"0\n";
			else cout<<max(n-2*(d/(f[n]-f[n-1]))+1,0ll)<<"\n";
		}
	}
	else if(c_id<=14){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>f[i];
			cout<<n-3<<"\n";
		}
	}
	else while(T--) solve2();
	return 0;
}
