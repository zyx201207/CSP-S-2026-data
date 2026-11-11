//GZ-S00037,刘一萱，贵阳市第一中学 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=501;
const int M=5e4+1;
ll n,m,c,d,q,k,x,y,aa,bb;
ll a[N],w[N],t[N][N],g[N][N],f[N],cnt[N],q2[N],q3[N];
queue<ll> qu,q1;
vector<ll> e[N];
void f1(){
	while(!qu.empty()){
		ll u=qu.front();
		ll k1=q1.front();
		q1.pop();
		qu.pop();
		for (int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if (k1==0 || g[v][u]==k1){
				if (f[v]>f[u]){
					f[v]=f[u];
					q3[v]=u;
					if (q2[u]==0){
						q2[v]=g[v][u];
					}
					else{
						q2[v]=q2[u];
					}
					if (v==y){
						bb=g[v][u];
						aa=q2[v];
					}
				}
			}
			else if (g[v][u]!=k1){
				if (f[v]>f[u]+t[k1][u]+t[g[v][u]][u]){
					f[v]=f[u]+t[k1][u]+t[g[v][u]][u];
					q3[v]=u;
					if (q2[u]==0){
						q2[v]=g[v][u];
					}
					else{
						q2[v]=q2[u];
					}
					if (v==y){
				 		bb=g[v][u];
				 		aa=q2[v];
					}
				}
			}
			if (!cnt[v]){
				cnt[v]=1;
				qu.push(v);
				q1.push(g[v][u]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a[j];
			cin>>t[i][a[j]];
			if (j!=1){
				g[a[j]][a[j-1]]=g[a[j-1]][a[j]]=i;
				e[a[j]].push_back(a[j-1]);
				e[a[j-1]].push_back(a[j]);
			}
		}
	}
	for (int l=1;l<=q;l++){
		cin>>x>>y;
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		memset(q2,0,sizeof(q2));
		qu.push(x);
		q1.push(0);
		cnt[x]=1;
		f[x]=0;
		f1();
		cout<<(f[y]+w[x]+w[y]+t[aa][x]+t[bb][y])<<endl;
	}
	return 0;
}
