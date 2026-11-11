#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &n){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
void read(ll &n){ll x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll ww[M];
vector<ll>g[M],w[M];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++)read(ww[i]);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
//	for(int i=1;i<=10;i++)
//	cout<<f[1][2]*i<<endl;return 0;
	for(ll k,a,t,i=1;i<=n;i++){
		read(k);
		while(k--){
			read(a);read(t);
			for(int j=0;j<g[a].size();j++){
//				cout<<i<<">"<<g[a][j]<<endl;
				f[i][g[a][j]]=min(f[i][g[a][j]],t+w[a][j]);
			}
			g[a].push_back(i);w[a].push_back(t);
		}
		for(int j=1;j<i;j++)f[j][i]=f[i][j];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	cout<<f[1][2]<<endl;
	for(int x,y,i=1;i<=q;i++){
		read(x);read(y);
		ll ans=f[501][0];
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,w[x][i]+w[y][j]+f[g[x][i]][g[y][j]]);
			}
		}
		cout<<ans+ww[x]+ww[y]<<'\n';
	}
	return 0;
}
