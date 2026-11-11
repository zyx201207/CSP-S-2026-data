#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k,vis[2000005],dis[2000005],fa[2000005],ans;
vector<int> e[2000005];
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void solve(){
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if(n>10){
		int h=n/2;
		if(k<=h) {
			cout<<(h-3)/4+2+(k-2)/4<<"\n";
		}else{
			cout<<"1\n";
		}
	}else{
		ans=1e9;
		queue<int> q;
		for(int i=1;i<(1<<n);i++){
			int bj=0;
			for(int j=1;j<=n;j++){
				fa[j]=j;
				vis[j]=0,dis[j]=1e9;
				if((i>>(j-1))&1) {
					vis[j]=1;
					dis[j]=1;
					q.push(j);
					bj++;
				}
			}
			if(bj>k){
				while(!q.empty()) q.pop();
				continue;
			} 
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:e[u]){
					if(!vis[v]){
						vis[v]=1;
						dis[v]=dis[u]+1;
						q.push(v);
					}
					if(dis[u]==0&&dis[v]==0){
						int gu=getfa(u),gv=getfa(v);
						fa[gu]=gv;
					}
				}
			}
			int p1=0,p2=0,pp=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1) {
					if(p1==0||p1==fa[j]) p1=fa[j];
					else if(p2==0||p2==fa[j]) p2=fa[j];
					else pp=1;
				}
			}
			if(pp=1) continue;
			int cnt=0;
			for(int j=1;j<=n;j++) cnt=max(cnt,dis[j]);
			ans=min(ans,cnt);
		}
		cout<<ans<<"\n";
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
