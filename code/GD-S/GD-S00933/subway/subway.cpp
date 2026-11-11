#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
	bool operator <(const node &t)const{
		return t.y<y;
	}
};
int c,n,m,d,_;
long long w[500010],f[510][510];
int v[500010][30],tot[500010];
long long v1[500010][30];
vector<long long>e[510],e1[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>_;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		long long k,a,t;
		scanf("%lld",&k);
		for(int j=1;j<=n;j++)f[i][j]=1e18;
		f[i][i]=0;
		int j=0,kl;
		int sz;
		long long kll=0;
		for(int o=1;o<=k;o++){
			scanf("%lld%lld",&a,&t);
			sz=tot[a];
			for(kl=1;kl<=sz;kl++){
				e[i].push_back(v[a][kl]);
				e[v[a][kl]].push_back(i);
				e1[i].push_back(t+v1[a][kl]);
				e1[v[a][kl]].push_back(t+v1[a][kl]);
			}
			v[a][++tot[a]]=i;
			v1[a][tot[a]]=t;
		}
	}
	long long x,y;
	for(int i=1;i<=n;i++){
		priority_queue<node>q;
		q.push({i,0});
		long long kx,ky;
		while(!q.empty()){
			x=q.top().x,y=q.top().y;
			q.pop();
			if(y>f[i][x])continue;
			int sz=e[x].size();
			for(int j=0;j<sz;j++){
				kx=e[x][j],ky=e1[x][j];
				if(f[i][kx]>y+ky){
					f[i][kx]=y+ky;
					q.push({kx,y+ky});
				}
			}
		}
	}
	long long ret=0;
	while(_--){
		scanf("%lld%lld",&x,&y);
		ret=1e18;
		int sz1=tot[x],sz2=tot[y];
		for(int i=1;i<=sz1;i++){
			for(int j=1;j<=sz2;j++){
				ret=min(ret,f[v[x][i]][v[y][j]]+v1[x][i]+v1[y][j]);
			}
		}
		printf("%lld\n",w[x]+w[y]+ret);
	}
	return 0;
}
