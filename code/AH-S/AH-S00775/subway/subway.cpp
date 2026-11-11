#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ultra unsigned __int128
/*
struct edge{
	int to,from,val;
}e[1000001];
int head[1000001],cnt;
void add(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].val = w;
	e[cnt].from = head[u];
	head[u] = cnt;
}*/
struct station{
	int cnt;//有多少地铁经过
	vector<int> pa,va;//经过的地铁编号，所需站厅到站台距离
	int inn;//自身的路程 
}st[1000001];
int c,n,m,d,q;
int dis[1001][1001];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	int k,u,v,w;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w);
		st[i].inn = w;
		st[i].pa.push_back(0);
		st[i].va.push_back(0);
	}
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
		scanf("%lld",&k);
		for(int j = 1;j <= k;j++){
			scanf("%lld%lld",&v,&w);
			st[v].cnt++;
			st[v].pa.push_back(i);
			st[v].va.push_back(w); 
		}
	}
//	cout<<st[3].va[0]<<" "<<st[3].va[1]<<" "<<st[3].va[2]<<endl; 
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= st[i].cnt;j++){
			for(int k = j + 1;k <= st[i].cnt;k++){
				dis[st[i].pa[j]][st[i].pa[k]] = min(dis[st[i].pa[j]][st[i].pa[k]],st[i].va[j] + st[i].va[k]);
				dis[st[i].pa[k]][st[i].pa[j]] = min(dis[st[i].pa[k]][st[i].pa[j]],st[i].va[j] + st[i].va[k]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j)continue;
			for(int k = 1;k <= n;k++){
				if(j == k || i == k)continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
//	cout<<dis[0][0]<<endl;
	int ans = max(dis[0][0],2147483648);
	//cout<<dis[1][2]<<" "<<dis[2][1]<<endl;
	for(int i = 1;i <= q;i++){
		ans = max(dis[0][0],2147483648);
		scanf("%lld%lld",&u,&v);
	//	cout<<"!"<<u<<" "<<v<<endl;
		for(int j = 1;j <= st[u].cnt;j++){
		//	cout<<"."<<" "<<st[u].cnt<<endl;
			for(int k = 1;k <= st[v].cnt;k++){
				//cout<<"?"<<" "<<st[v].cnt<<endl;
				//cout<<st[u].pa[j]<<" "<<st[v].pa[k]<<" "<<v<<" "<<k<<" "<<endl;
				ans = min(ans,dis[st[u].pa[j]][st[v].pa[k]] + st[u].inn + st[v].inn + st[u].va[j] + st[v].va[k]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

