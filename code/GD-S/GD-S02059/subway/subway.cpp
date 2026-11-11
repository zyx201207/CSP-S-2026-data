#include<bits/stdc++.h>
#define gc getchar
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
using namespace std;
const int N=1010,M=1e5+5;
const long long inf=1e18;
inline void re(int &s){
	s=0;
	char a=gc();
	short f=1;
	while(!isdigit(a)){
		if(a=='-') f=-1;
		a=gc();
	}
	while(isdigit(a)){
		s=(s<<3)+(s<<1)+(a-'0');
		a=gc();
	}
	s*=f;
}
inline void rel(long long &s){
	s=0;
	char a=gc();
	short f=1;
	while(!isdigit(a)){
		if(a=='-') f=-1;
		a=gc();
	}
	while(isdigit(a)){
		s=(s<<3)+(s<<1)+(a-'0');
		a=gc();
	}
	s*=f;
}
int i,j,n,m,q,l,d,tmp,c,t,x,y;
vector<pii>g[M];
long long a[N][N],w[N];
long long ans;
void pu(long long s){
	if(s>9) pu(s/10);
	putchar(s%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	re(c),re(n),re(m),re(d),re(q);
	for(int i=1;i<=m;i++) rel(w[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) a[j][i]=a[i][j]=inf;
	}
		
	for(int i=1;i<=n;i++){
		re(tmp);
		for(int j=1;j<=tmp;j++){
			re(x);
			re(y);
			g[i].pb(mk(x,y));
		}
		for(int u,j=0;j<g[i].size();j++){
			u=g[i][j].first;
			for(int v,p=j+1;p<g[i].size();p++){
				v=g[i][p].first;
				a[v][u]=a[u][v]=min(a[u][v],1LL*(g[i][j].second*1LL+1LL*g[i][p].second));
			}	
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		re(x);re(y);
		ans=a[x][y]+w[x]+w[y];
		pu(ans);
		putchar('\n');
	}
	return 0;
}
