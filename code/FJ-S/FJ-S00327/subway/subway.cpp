#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=510,M=5e5+5;
ll D[N][N],D_[N],c,n,m,d,q,w[M];
basic_string<pair<int,ll> >e[M];
inline int R(){int a=0;char c=getchar();for(;c<48||c>57;c=getchar());
	for(;c>47&&c<58;c=getchar())a=(a<<1)+(a<<3)+(c^48);return a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=R(),n=R(),m=R(),d=R(),q=R();
	for(int i=1;i<=m;i++)w[i]=R();
	for(int i=1;i<=n;i++)for(ll k=R(),x,y;k--;)x=R(),y=R(),e[x]+={i,y};
	memset(D,0x3f,sizeof D);
	for(int i=1;i<=n;i++)D[i][i]=0;
	for(int i=1;i<=m;i++)for(auto u:e[i]){ll y=u.first;
		for(auto U:e[i]){ll Y=U.first;
			if(Y^y)D[Y][y]=D[y][Y]=min(D[Y][y],U.second+u.second);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)
		for(int k=j+1;k<=n;k++)if(i!=k)
			D[k][j]=D[j][k]=min(D[j][i]+D[i][k],D[j][k]);
	for(int x,y;q--;){x=R(),y=R();ll A=1e18;
		for(auto u:e[x])for(auto U:e[y])
			A=min(A,D[u.first][U.first]+u.second+U.second);
		printf("%lld\n",A+w[x]+w[y]);
	}
	return 0;
}/*
15:50
*/
