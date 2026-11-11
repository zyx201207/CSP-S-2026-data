#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
typedef pair<ll,ll> PLL;
ll c,n,m,d,q,x,y,tx,ty,a,b,num;
ll w[N];
ll v[5005][5005];
ll dist[N];
bool vis[N];
ll ans[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	fill(dist+1,dist+1+m,1000000000000);
	if(c>=7 && c<=11){
		for(int i=1;i<=m;i++){
			cin >>w[i];
		}
		for(int i=1;i<=n;i++){
			cin >>num;
			if(num==1) continue;
			cin >>x>>y;
			cin >>tx>>ty;
			v[x][tx]=y+ty;
			v[tx][x]=y+ty;
		}
		for(int aa=1;aa<=m;aa++){
			fill(dist+1,dist+1+m,1000000000000);
			fill(vis+1,vis+1+m,0);
			priority_queue<PLL,vector<PLL>,greater<PLL>> q;
			dist[aa]=w[aa];
			ans[aa][aa]=dist[aa];
			q.push({w[aa],aa});
			//cout <<1<<'\n';
			while(!q.empty()){
				ll val=q.top().first,idx=q.top().second;
				q.pop();
				vis[idx]=1;
				for(int i=1;i<=m;i++){
					if(v[idx][i] && i!=idx && vis[i]==0){
						if(dist[idx]+v[idx][i]<dist[i]){
							dist[i]=dist[idx]+v[idx][i];
							ans[aa][i]=dist[i];
							q.push({dist[i],i});
						}
					}
				}
			}
			
		}
		for(int i=1;i<=q;i++){
			cin >>a>>b;
			cout <<ans[a][b]+w[b]<<'\n';
		}
	}
	
		
	return 0;
}
