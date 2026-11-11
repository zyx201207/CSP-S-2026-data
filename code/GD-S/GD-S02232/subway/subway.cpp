#include<bits/stdc++.h>
using namespace std;
const int N = 510,M = 5e5+10;
int c,n,m,d,q,w[M],h[M],k,a,b,idx;
long long f[N][N];
struct edge{
	int v,w,ne;
}g[M*4];
void add(int a,int b,int w){
	g[++idx] = {b,w,h[a]};
	h[a] = idx;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 0;i<N;i++){
		for(int j = 1;j<N;j++){
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>a>>b;//第i个源点链接的地铁站和时间 
			for(int o = h[a],v,w;o;o = g[o].ne){
				v = g[o].v,w = g[o].w;
				f[v][i] = f[i][v] = min(f[v][i],(long long)w+b);
			}
			add(a,i,b);
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<i;j++){
				f[i][j] = f[j][i] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i = 1;i<=q;i++){
		cin>>a>>b;
		long long ans = 1e18;
		for(int o1 = h[a],v1,w1;o1;o1 = g[o1].ne){
			v1 = g[o1].v,w1 = g[o1].w;//这一块忘写了 
			for(int o2 = h[b],v2,w2;o2;o2 = g[o2].ne){
				v2 = g[o2].v,w2 = g[o2].w;
				ans = min(ans,w1+w2+f[v1][v2]);
			}
		}
		cout<<ans+w[a]+w[b]<<"\n";
	}
	return 0;
}

