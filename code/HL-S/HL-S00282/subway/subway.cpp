#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+10;
int c,n,m,d,q;
int dis[N][N],t[M];
vector<pair<int,int> > v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,y;scanf("%lld%lld",&x,&y);
			for(int q=0;q<v[x].size();q++){
				int a=v[x][q].first,b=v[x][q].second;
				dis[i][a]=dis[a][i]=min(dis[i][a],b+y);
			}
			v[x].push_back(make_pair(i,y));
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	for(int op=1;op<=q;op++){
		int x,y;scanf("%lld%lld",&x,&y);
		int ans=1e18;
		for(int ii=0;ii<v[x].size();ii++){
			for(int jj=0;jj<v[y].size();jj++){
				pair<int,int> i=v[x][ii],j=v[y][jj];
				ans=min(ans,t[x]+t[y]+i.second+j.second+dis[i.first][j.first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
lcy6 shuo ta yao gao HL CSPS2026 pin jian,suo yi wo lai zheng ge huo.
guan zhu luogu 748015 xie xie miao.

hua shuo,zhen de hui you di tie zhan you 20 tiao di tie jing guo,cheng shi you 500 tiao di tie he 5e5 ge di tie zhan?
ha er bin you zheng zheng 3 tiao di tie,wo men de sheng hui tai fan hua le!

15:03 bu dui a wo zen me hao xiang hui B le
bu guan ni shi shei,gan jin cong wo shen shang xia lai!

15:15 xie wan le yang li dou guo le,xin tai +10
dan shi zui man de dian pao le 2s.

15:20 ke wu zen me kao shi de ji zi 1e8 pao le 2s,dian nao ji xiang shi tu dou qu dong de? fn fn fn
*/
