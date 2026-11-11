#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
const int N=505,M=5e5+5;
lo C,n,m,d,q,w[M],dis[N][N];
vector<pair<lo,lo>>ve[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(lo i=1;i<=m;++i)cin>>w[i];
	for(lo i=1;i<=n;++i)for(lo j=i+1;j<=n;++j)
		dis[i][j]=dis[j][i]=1e18;
	for(lo i=1,k;i<=n;++i)
	{
		cin>>k;
		for(lo j=1,a,t;j<=k;++j)
			cin>>a>>t,ve[a].emplace_back(i,t);
	}
	for(lo i=1;i<=m;++i)
	{
		lo sz=ve[i].size();
		for(lo j=0;j<sz;++j)for(lo k=j+1;k<sz;++k)
		{
			auto[u,w1]=ve[i][j];
			auto[v,w2]=ve[i][k];
			dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);
		}
	}
	for(lo k=1;k<=n;++k)for(lo i=1;i<=n;++i)
		for(lo j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(lo i=1,x,y;i<=q;++i)
	{
		cin>>x>>y;lo mn=1e18;
		for(auto[u,w1]:ve[x])for(auto[v,w2]:ve[y])
			mn=min(mn,dis[u][v]+w1+w2);
		cout<<mn+w[x]+w[y]<<'\n';
	}
}
/*
也算作一雪前耻

我们乘坐的末班列车
在缺损的轨道上行驶着
询问沉默的乘客
遗憾着为何
着急彻底消失在夜色
他说
我不记得我不记得了
我不记得我不记得了
——灯诱 Lampture《人生逃避號》 
*/
