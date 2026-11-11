#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s(0), ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+ch-'0';
	return s;
}
long long w[500005], k[505];
vector<long long> a[505], t[505];
struct o{
	long long val, id;
	bool operator<(const o& other) const{
		return val > other.val;
	}
}tt;
long long dis[500005];
//long long solve(long long st, long long en){
//	priority_queue<o> q;
//	dis[st]=0;
//	q.push({0, st}); 
//	while(!q.empty()){
//		tt=q.top();
//		q.pop();
//		if(tt.val > dis[tt.id]) continue;
//		long long u=tt.id, s=tt.val, m=jl[u];
//		if(u==en) break;
//		for(int i=0;i<m;i++){
//			
//		}
//	}
//	return dis[en];
//}
long long p[405][405];
struct oo{
	long long wz, fy;
};
vector<oo> jl[500005];
long long x[500005], y[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c=read(), n=read(), m=read(), d=read(), q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			long long u=read(), w=read();
			jl[u].push_back({i, w});
			a[i].push_back(u);
			t[i].push_back(w);
		}
	}
	if(m<=400 || 1){
		for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) p[i][j]=1e16;
		for(int i=1;i<=m;i++){
			for(int j=0;j<jl[i].size();j++){
				long long xl=jl[i][j].wz, hf=jl[i][j].fy;
				for(int l=0;l<k[xl];l++){
					long long v=a[xl][l];
					p[v][i]=p[i][v]=min(p[i][v], hf+t[xl][l]);
				}
			}
		}
		for(int i=1;i<=m;i++) p[i][i]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					p[i][j]=p[j][i]=min(p[i][j], p[i][k]+p[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			x[i]=read(); 
			y[i]=read();
			
		}
		for(int i=1;i<=q;i++){
			cout << p[x[i]][y[i]]+w[x[i]]+w[y[i]] << '\n';
		}
		return 0;
	}
//	for(int i=1;i<=q;i++){
//		x=read();
//		y=read();
//		for(int j=1;j<=m;j++) dis[j]=1e18;
//		cout << solve(x, y) << '\n';
//	}
	return 0;
}
