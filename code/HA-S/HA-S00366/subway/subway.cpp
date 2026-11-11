#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll x;cin>>x;return x;}
const int N=5e5+510;
ll n,m,d,Q,tot,w[N],dis[510][20510],dis1[5][N];
vector<pair<ll,ll>>Link[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q; 
void work(){
	memset(dis1,0x3f3f3f,sizeof(dis1));
	for(int i=m+1;i<=tot;i++){
		int j=i-m;
		dis1[j][i]=0;
		q.push({0,i});
		while(!q.empty()){
			ll x=q.top().second,num=q.top().first;
			q.pop();
			if(dis1[j][x]<num) continue;
			for(auto o:Link[x]){
				ll y=o.first,val=o.second;
				if(dis1[j][x]+val<dis1[j][y]){
					dis1[j][y]=dis1[j][x]+val;
					q.push({dis1[j][y],y});
				}
			}
		}
	}
	while(Q--){
		int x=read(),y=read();
		ll ans=1e18;
		for(int i=m+1;i<=tot;i++)
			ans=min(ans,dis1[i-m][x]+dis1[i-m][y]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int c=read();
	n=read(),tot=m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		tot++;
		for(int j=1;j<=k;j++){
			ll x=read(),val=read();
			Link[x].push_back({tot,val});
			Link[tot].push_back({x,val});
		}
	}
	memset(dis,0x3f3f3f,sizeof(dis));
	if(n<=2){work();return 0;}
	for(int i=m+1;i<=tot;i++){
		int j=i-m;
		dis[j][i]=0;
		q.push({0,i});
		while(!q.empty()){
			ll x=q.top().second,num=q.top().first;
			q.pop();
			if(dis[j][x]<num) continue;
			for(auto o:Link[x]){
				ll y=o.first,val=o.second;
				if(dis[j][x]+val<dis[j][y]){
					dis[j][y]=dis[j][x]+val;
					q.push({dis[j][y],y});
				}
			}
		}
	}
	while(Q--){
		int x=read(),y=read();
		ll ans=1e18;
		for(int i=m+1;i<=tot;i++)
			ans=min(ans,dis[i-m][x]+dis[i-m][y]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
