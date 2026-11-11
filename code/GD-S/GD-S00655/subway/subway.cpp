#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	char c='?';
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return;
}
const int N=505,M=500005,D=25;
int c,n,m,d,q,siz[M],a[M][D],b[M][D],w[M],cnt,x,y;
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)dis[i][j]=1000000000000000000ll;
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(cnt);
		while(cnt--){
			read(x);
			siz[x]++;
			a[x][siz[x]]=i;
			read(b[x][siz[x]]);
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=siz[i];j++)
			for(int k=1;k<=siz[i];k++)dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],(long long)b[i][j]+b[i][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		read(x),read(y);
		long long ans=1000000000000000000ll;
		for(int i=1;i<=siz[x];i++)
			for(int j=1;j<=siz[y];j++)ans=min(ans,(long long)w[x]+w[y]+b[x][i]+b[y][j]+dis[a[x][i]][a[y][j]]);
		cout<<ans<<'\n';
	}
	return 0;
}
