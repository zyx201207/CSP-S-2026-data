#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=505;
const int N=5e5+5;
ll dis[MAXN][MAXN];
int w[N];
vector<pair<int,ll> >hav[N];
int c,n,m,d,q;
ll read(){
	ll num=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while('0'<=c&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	} 
	return num;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int p,t;
			p=read();t=read();
			hav[p].push_back(make_pair(i,(ll)t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18+9;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<hav[i].size();j++){
			for(int k=0;k<hav[i].size();k++){
				if(j==k)continue;
				dis[hav[i][j].first][hav[i][k].first]=min(dis[hav[i][j].first][hav[i][k].first],hav[i][j].second+hav[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ll ans=1e18+9;
		x=read();y=read();
		for(int j=0;j<hav[x].size();j++){
			for(int k=0;k<hav[y].size();k++){
				ans=min(ans,hav[x][j].second+dis[hav[x][j].first][hav[y][k].first]+hav[y][k].second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
