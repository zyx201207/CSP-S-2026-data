#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
const ll MAXN=1e18;
int n,m,c,d,q,x,y,k,sz[maxn];
ll cnt,w[maxn],dis[505][505];
vector<int> v[maxn];
vector<ll> t[maxn];
void work(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=MAXN;
	for(int i=1;i<=m;i++){
		if(sz[i]<=1) continue;
		for(int ii=0;ii<sz[i];ii++){
			for(int jj=0;jj<sz[i];jj++){
				if(ii==jj) continue;
				if(dis[v[i][ii]][v[i][jj]]>t[i][ii]+t[i][jj])
					dis[v[i][ii]][v[i][jj]]=dis[v[i][jj]][v[i][ii]]=t[i][ii]+t[i][jj];
			}
		} 
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j or i==kk or kk==j) continue;
				if(dis[i][j]>dis[i][kk]+dis[kk][j]) dis[i][j]=dis[j][i]=dis[i][kk]+dis[kk][j];
			}
		}
	}
	return;
}
ll ask(int x,int y){
	cnt=MAXN;
	for(int i=0;i<sz[x];i++){
		for(int j=0;j<sz[y];j++){
			cnt=min(cnt,dis[v[x][i]][v[y][j]]+t[x][i]+t[y][j]);
		}
	}
	return cnt+w[x]+w[y];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;sz[x]++;
			t[x].push_back(y);v[x].push_back(i);
		}
	}
	work();
	while(q--){
		cin>>x>>y;
		cout<<ask(x,y)<<"\n";
	}
	return 0;
} 
