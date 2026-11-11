#include<bits/stdc++.h>
#define ll long long 
using namespace std;
using pii=pair<int,int>;
const int N=2e6+10;
ll x[N];
int dis[N],a[N];
vector<int> e[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,ans=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			priority_queue<pii,vector<pii>,greater<pii>> q;
			q.push({i,0});
			memset(dis,0x3f,sizeof(dis));
			memset(a,0,sizeof(a));
			dis[i]=0;
			while(!q.empty()){
				int p=q.top().first,d=q.top().second;
				q.pop();
				if(dis[p]==d) a[p]++;
				if(dis[p]<d) continue;
				for(int j:e[p]){
					if(d+1<=dis[j]){
						dis[j]=d+1;
						q.push({j,dis[j]});
					}
				}
			}	
			for(int j=i+1;j<=n;j++) if(a[j]==2) ans++;
		} 
		cout<<ans<<'\n';
	} 
	return 0;
} 
