#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){char ch=getchar();int f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}ll x=0;while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int c,n,m,d,q;
const int M=5e5+5,N=505;
int wt[M];
vector<pair<int,int>> fr[M];
ll w[N][N];
const ll inf=1e18;
ll ans;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)wt[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=inf;
	for(int i=1;i<=n;i++)w[i][i]=0;
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int u=read(),tu=read();
			for(pair<int,int> tmp:fr[u]){
				int v=tmp.first,tv=tmp.second;
				w[v][i]=min(w[v][i],(ll)tu+tv);
				w[i][v]=min(w[i][v],(ll)tu+tv);
			}
			fr[u].emplace_back(i,tu);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(w[i][k]==inf)continue;
			for(int j=1;j<=n;j++){
				if(w[k][j]==inf)continue;
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ans=inf;
		for(pair<int,int> tmpu:fr[x]){
			int u=tmpu.first,tu=tmpu.second;
			for(pair<int,int> tmpv:fr[y]){
				int v=tmpv.first,tv=tmpv.second;
				ans=min(ans,w[u][v]+tu+tv);
			}
		}
		write(ans+wt[x]+wt[y]);
		puts("");
	}
	return 0;
}
/*
10 118 45 119 76 120 17 121 54 122 38 123 67 124 35 125 60 126 45 127 82
10 127 54 128 38 129 54 130 73 131 53 132 5 133 53 134 20 135 26 136 1
*/
