#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128
#define mkp make_pair
const int N=5e5+5,inf=1e18;
struct Point{
	int v,val;
};
int cid,n,m,D,q,a[N],b[505][505];
vector <Point> s[N];
int calc(int st,int ed){
	if(st==ed)return 0;
	int ans = inf,len1=(int)s[st].size(),len2=(int)s[ed].size();
	for(int i = 0;i < len1;i++){
		for(int j = 0;j < len2;j++){
			int u = s[st][i].v,v = s[ed][j].v; 
			ans=min(ans,b[u][v]+s[st][i].val+s[ed][j].val);
		}
	}return ans+a[st]+a[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> cid >> n >> m >> D >> q;memset(b,0x3f,sizeof(b));
	for(int i = 1;i <= m;i++)cin >> a[i];
	for(int i = 1,k;i <= n;i++){
		cin >> k;b[i][i]=0;
		for(int j = 1,x,d;j <= k;j++){
			cin >> x >> d;
			s[x].push_back((Point){i,d}); 
		}
	}
	for(int i = 1;i <= m;i++){
		int len = (int)s[i].size();
		for(int j = 0;j < len;j++){
			for(int k = 0;k < len;k++){
				int u = s[i][j].v,v = s[i][k].v;
				b[u][v]=min(b[u][v],s[i][j].val+s[i][k].val);
			}
		}
	}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	for(int i = 1,u,v;i <= q;i++){
		cin >> u >> v;
		cout << calc(u,v) << "\n";
	}
	return 0;
}
/*
我状态太差了吧。读了20分钟题hhh
地铁口搞笑的。站台看成点，线路也是点
然后做法应该是，由于每个站台线路少
然后先处理线路之间的最短路
然后考虑枚举一下这个出入口
时间复杂度O(n^3+qd^2+md)左右
4e8?能跑吗兄弟
跑不满吧 
*/
