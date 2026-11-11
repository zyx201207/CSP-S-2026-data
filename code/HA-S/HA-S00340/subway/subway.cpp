//subway
#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q,w[500005],a[505][50005],k[505],t[505][50005],x,y,to[100005],val[100005],nxt[100005],h[100005],cnt,dis[1005];
bool ok[1005];
priority_queue <pair<int,int> > qq;

void add(int aa,int bb,int cc){
	to[++ cnt] = bb;//去向 
	val[cnt] = cc;//权值 
	nxt[cnt] = h[aa];//第cnt条边的下一条边 
	h[aa] = cnt;//以a开头的第一条边 
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i ++){
		cin>>w[i];
		add(i,i + m,w[i]);
		add(i + m,i,w[i]);
	}
	for (int i = 1;i <= n;i ++){
		cin>>k[i];
		for (int j = 1;j <= k[i];j ++){
			cin>>a[i][j]>>t[i][j];
		}
		for (int j = 1;j <= k[i];j ++){
			for (int kk = j + 1;kk <= k[i];kk ++){
				add(a[i][j],a[i][kk],t[i][j] + t[i][kk]);
				add(a[i][kk],a[i][j],t[i][j] + t[i][kk]);
			}
		}
	}
	while (q --){
		cin>>x>>y;
		x += m;
		y += m;
		memset(ok,0,sizeof ok);
		while (qq.size()){
			qq.pop();
		}
		for (int i = 1;i <= 2 * m;i ++){
				dis[i] = 0x7fffffff;
		}
		dis[x] = 0;
		qq.push({0,x});
		while (qq.size()){
			int kk = qq.top().second;
			qq.pop();
			if (ok[kk]){
				continue;
			}
			ok[kk] = 1;
			for (int i = h[kk];i;i = nxt[i]){
				if (dis[kk] + val[i] < dis[to[i]]){
					dis[to[i]] = dis[kk] + val[i];
					qq.push({-dis[to[i]],to[i]});
				}
			}
		}
		cout<<dis[y]<<endl;;
	}
	return 0;
}
