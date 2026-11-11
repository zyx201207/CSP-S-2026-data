#include<bits/stdc++.h>
using namespace std;
constexpr int M=5e5+20,N=520,D=25;
constexpr long long MAXN=LONG_LONG_MAX;
struct f{ long long node,num; };
long long c,n,m,d,q;
long long w[M],k[N],t[N][D],a[N][D],G[N][N];
vector<f> s[M];
void input();
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	for(int i=1;i<=m;++i){
		long long wn=s[i].size();
		if(wn>1)
			for(int j=0;j<wn;++j)
				for(int l=j+1;l<wn;++l){
					G[s[i][j].node][s[i][l].node]=t[s[i][j].node][s[i][j].num]+t[s[i][l].node][s[i][l].num];
					G[s[i][l].node][s[i][j].node]=t[s[i][j].node][s[i][j].num]+t[s[i][l].node][s[i][l].num];
				}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(G[i][k]!=0&&G[j][k]!=0){
					if(G[i][j]==0) G[i][j]=G[j][i]=G[i][k]+G[j][k];
					else{
						G[i][j]=min(G[i][j],G[i][k]+G[j][k]);
						G[j][i]=G[i][j];
					}
				}

			}
		}
	}
	for(int l=1;l<=q;++l){
		long long x,y,minn=MAXN,n1,n2;
		scanf("%lld%lld",&x,&y);n1=s[x].size();n2=s[y].size();
		for(int i=0;i<n1;++i){
			for(int j=0;j<n2;++j){
				minn=min(minn,G[s[x][i].node][s[y][j].node]+t[s[x][i].node][s[x][i].num]+t[s[y][j].node][s[y][j].num]);
			}
		}
		long long ll=w[x]+w[y];
		printf("%lld\n",minn+ll);
	}
	return 0;
}
void input(){
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];++j) {
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			s[a[i][j]].push_back({i,j});
		}
	}
}
