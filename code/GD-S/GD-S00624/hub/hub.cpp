#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5,M=305;
ll Taskid,Q;
ll n,k;
ll maxx,maxi,U,V;
vector<ll>G[N],c;
bool fl,vis[N];
ll Dis[N],ans,t[5];
//==================================================
inline void Clean(){
	for(int i=0;i<=n;i++){
		G[i].clear();
		vis[i]=false;
	}
}
void DFS_Len(ll now,ll fa,ll dis){
	if(dis>=maxx) maxx=dis,maxi=now;
	for(auto nxt:G[now]){
		if(nxt==fa||vis[nxt]) continue;
		DFS_Len(nxt,now,dis+1);
	}
}
void Get_Len(ll now,ll fa){
	if(now==V){ fl=true; c.push_back(now); return ; }
	for(auto nxt:G[now]){
		if(nxt==fa) continue;
		Get_Len(nxt,now);
		if(fl) break;
	} if(fl) c.push_back(now);
}
inline void check(){
	ll x=t[1],y=t[2],z=t[3];
	if(z-y+1>k) return;
	if(x!=y&&z-y+1+1>k) return ;
	ll len=z-y+1;
	if(x!=y) ++len;
	ll now=0;
	for(int i=0;i<c.size();i++) now=max(now,Dis[c[i]]);
//	cout<<"!!"<<now<<'\n';
	for(int i=x+1;i<y;i++)
		now=max(now,Dis[c[i]]+min(i-x,y-i));
	for(int i=z+1;i<c.size();i++) now=max(now,Dis[c[i]]+i-z);
//	cout<<"!!"<<now<<'\n';
	for(int i=0;i<=x;i++){
		if(i!=0) ++now,now=max(now,Dis[c[i-1]]+1);
//		cout<<"&&\n";
		if(len+(x-1)-i+1>k) continue;
		break;
	} 
	ans=min(ans,now);
//	cout<<x<<' '<<y<<' '<<z<<' '<<now<<'\n';
}
void Opt(ll mj,ll x){
	if(x>3){
		check();
		return ;
	}
	for(int i=mj;i<c.size();i++){
		t[x]=i;
		Opt(i,x+1);
	}
}
//==================================================
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>Taskid>>Q;
	while(Q--){
		cin>>n>>k;
		Clean();
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		maxx=0,maxi=1;
		DFS_Len(1,0,0); U=maxi;
		maxx=0,maxi=U;
		DFS_Len(maxi,0,0); V=maxi;
		fl=false; c.clear();
		Get_Len(U,0);
//		cout<<U<<' '<<V<<'\n';
		for(auto it:c) vis[it]=true;
//		cout<<'\n';
		for(auto it:c){
			maxx=0;
			DFS_Len(it,0,0);
			Dis[it]=maxx;
//			cout<<it<<": "<<Dis[it]<<'\n';
		}
		ans=LLONG_MAX;
		Opt(0,1);
		cout<<ans<<'\n';
	}
	return 0;
} 
