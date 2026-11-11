#include<bits/stdc++.h>
using namespace std;
void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;
}
const int N=1e6+5;
const long long inf=1e18;
int c,n,m,d,q,w[N];
vector<int>v[N];
vector<long long>val[N];
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	dd(c),dd(n),dd(m),dd(d),dd(q);
	int kk,x,y;
	for(int i=1;i<=m;++i)dd(w[i]);
	for(int i=1;i<=n;++i){
		dd(kk);
		for(int j=1;j<=kk;++j)
		dd(x),dd(y),v[x].push_back(i),val[x].push_back(y);
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(i!=j)
	dis[i][j]=dis[j][i]=inf;
	for(int i=1;i<=m;++i){
		int sx=v[i].size();
		for(int j=0;j<sx;++j)
		for(int k=0;k<sx;++k)
		dis[v[i][j]][v[i][k]]=min(dis[v[i][j]][v[i][k]],val[i][j]+val[i][k]);
	}
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		dd(x),dd(y);
		int sx=v[x].size(),sy=v[y].size();
		long long ans=inf;
		for(int i=0;i<sx;++i)
		for(int j=0;j<sy;++j)
		ans=min(ans,val[x][i]+val[y][j]+dis[v[x][i]][v[y][j]]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
