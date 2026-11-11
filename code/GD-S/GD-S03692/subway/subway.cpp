#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q,dis[N][N],w[M];
vector<pair<int,int>> lj[M];
inline int read()
{
	int s=0;char ai=getchar();
	while(ai<'0'||ai>'9') ai=getchar();
	while(ai>='0'&&ai<='9') s=s*10+ai-'0',ai=getchar();
	return s;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int len;len=read();dis[i][i]=0;
		for(int j=1,ai,bi;j<=len;j++) ai=read(),bi=read(),lj[ai].push_back({i,bi});
	}
	for(int i=1;i<=m;i++) for(int j=0;j<lj[i].size();j++) for(int k=j+1;k<lj[i].size();k++) dis[lj[i][j].first][lj[i][k].first]=dis[lj[i][k].first][lj[i][j].first]=min(dis[lj[i][j].first][lj[i][k].first],lj[i][j].second+lj[i][k].second);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1,ai,bi;i<=q;i++)
	{
		ai=read(),bi=read();int ans=0x3f3f3f3f3f3f3f3f;
		for(int x=0;x<lj[ai].size();x++) for(int y=0;y<lj[bi].size();y++) ans=min(ans,lj[ai][x].second+lj[bi][y].second+dis[lj[ai][x].first][lj[bi][y].first]);
		printf("%lld\n",ans+w[ai]+w[bi]);
	}
	return 0; 
}
