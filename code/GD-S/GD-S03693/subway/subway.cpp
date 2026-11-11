#include <bits/stdc++.h>
#define int long long
#define MAXM 500005
#define MAXN 505
using namespace std;
int c,n,m,d,q;
int w[MAXM],dis[MAXN][MAXN];
vector<pair<int,int>>a[MAXM];
void add(int x,int y,int z){
	dis[y][x]=dis[x][y]=min(dis[x][y],z);
}
int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=2e18;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),t=read();
			a[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int l=a[i].size();
		for(int j=0;j<l-1;j++)
			for(int k=j+1;k<l;k++)
				add(a[i][j].first,a[i][k].first,a[i][j].second+a[i][k].second);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]==dis[0][0])continue;
			for(int j=1;j<=n;j++){
				if(dis[k][j]==dis[0][0])continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read(),ans=LLONG_MAX;
		if(x==y){
			puts("0");
			continue;
		}
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++)
				ans=min(ans,dis[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second);
		ans+=w[x]+w[y];
		print(ans),puts("");
	}
	return 0;
}
