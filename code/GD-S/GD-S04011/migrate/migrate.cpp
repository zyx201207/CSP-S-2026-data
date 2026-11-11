#include<iostream>
#include<cstdio>
#include<vector>
#include<queue> 
#define ll long long
#define inf 1e12
#define N 2000010 
using namespace std;
vector<int>G[N];
int n;
ll ans,d,dis[N],a[N],cnt[N],vis[N];
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],G[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)G[i].push_back(j),G[j].push_back(i);
			else break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[j]=inf,cnt[j]=0,vis[j]=0;
		dis[i]=0,cnt[i]=1;
		queue<int>q;q.push(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto v:G[u]){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					cnt[v]=cnt[u];
					q.push(v);
				}
				else if(dis[u]+1==dis[v])
					cnt[v]+=cnt[u];
			}
		}
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2)
				ans++;
	}
	cout<<ans<<'\n';
	return;
}
void solA(){
	ll D;
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){
		cout<<0<<'\n';
		return;
	}
	D=a[2]-a[1];
	ll st=d/D;
	if(st<=1){
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
		if(i+st*2ll-1<=n)
			ans++;
	cout<<ans<<'\n';
	return;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cid,T;
	cin>>cid>>T;
	if(cid==11||cid==12){
		while(T--)
			solA();
		return 0; 
	}
	while(T--)
		solve();
	return 0;
}
