#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,k,ans,Timer;
const ll N=1e6+10,inf=1e18;
vector<ll>e[N];
queue<ll>q,q1;
bitset<N>vis,choose;
ll dis[N];
//bool flag;
mt19937 myr(time(0));
ll get(ll a,ll b){
	return myr()%(b-a+1)+a;
}
void bfs(ll s){
	q1.emplace(s);
//	if(flag)cout<<"start at "<<s<<"\n";
	while(q1.size()){
		ll u=q1.front();q1.pop();
//		if(flag)cout<<"come to "<<u<<"\n";
		if(vis[u])continue;
		vis[u]=1;
		for(ll v:e[u]){
//			if(flag)cout<<"consider "<<v<<" "<<vis[v]<<" "<<choose[v]<<"\n";
			if(vis[v])continue;
			if(choose[v]==0)continue;
//			if(flag)cout<<"ok!\n";
			q1.emplace(v);
		}
	}
}
void dfs(ll i,ll num){
	Timer++;
	if(Timer>=1e7)return;
	if(i>n){
		if(num!=k)return;
//		cout<<"data:\n";
//		for(ll i=1;i<=n;i++)cout<<choose[i]<<" ";
//		cout<<"\n";
		ll cnt=0;
//		if(n==10&&choose[2]&&choose[7]&&choose[9])flag=1;
		for(ll i=1;i<=n;i++)vis[i]=0;
		for(ll i=1;i<=n;i++){
			if(choose[i]==0||vis[i])continue;
//			if(flag)cout<<"start at "<<i<<"\n";
			bfs(i);
			cnt++;
		}
//		cout<<""
//		flag=0;
		if(cnt>2)return;
//		cout<<"legal\n";
		for(ll i=1;i<=n;i++){
			vis[i]=0,dis[i]=inf;
			if(choose[i]){
				dis[i]=0;
				q.emplace(i);
			}
		}
		while(q.size()){
			ll u=q.front();q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(ll v:e[u]){
				if(vis[v])continue;
				dis[v]=dis[u]+1;
				q.emplace(v);
			}
		}
		ll ma=0;
		for(ll i=1;i<=n;i++)ma=max(ma,dis[i]);
		ans=min(ans,ma);
		return;
	}
	ll choice=get(0,1);
	if(choice){
		if(num<k){
			choose[i]=1;
			dfs(i+1,num+1);
			choose[i]=0;
		}
		dfs(i+1,num);
	}
	else{
		dfs(i+1,num);
		if(num<k){
			choose[i]=1;
			dfs(i+1,num+1);
			choose[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
//		init();
//		flag=0;
		Timer=0;
		for(ll i=1;i<=n;i++)e[i].clear();
		ans=inf;
		for(ll i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
//		cout<<"---------------\n";
	}
	return 0;
} /*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1
2
*/
