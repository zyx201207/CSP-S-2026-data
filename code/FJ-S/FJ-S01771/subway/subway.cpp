#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
const int N=505,M=5e5+10,inf=1e17;

int n,m,q;
int a[M];
int dis[N][N];
vector<int> val[N];
vector<pair<int,int> > v[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),y=read();
			val[i].push_back(y);
			v[x].push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				int u1=v[i][j].first,v1=v[i][j].second;
				int u2=v[i][k].first,v2=v[i][k].second;
				dis[u2][u1]=dis[u1][u2]=min(dis[u1][u2],val[u2][v2-1]+val[u1][v1-1]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		int ans=inf;
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				int u1=v[x][j].first,u2=v[y][k].first;
				int v1=v[x][j].second,v2=v[y][k].second;
				ans=min(ans,dis[u1][u2]+val[u1][v1-1]+val[u2][v2-1]);
			}
		}
		write(ans+a[x]+a[y]);
		putchar('\n');
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/