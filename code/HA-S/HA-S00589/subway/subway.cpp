#include <bits/stdc++.h>
using namespace std;
//type
typedef pair<int,int> PII;
//contianer
int c,n,m,d,q,cnt,x,y;
priority_queue<PII,vector<PII>,greater<PII> > qq;
int w[500005];
int to[1000005],vail[1000005],nxt[1000005],h[500005];
long long dis[150020];
bool vis[150020];
//func
void add(int __a,int __b,int __c){
	to[++cnt] = __b;
	vail[cnt] = __c;
	nxt[cnt] = h[__a];
	h[__a] = cnt;
}
//main
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		for(int j=1;j<=m+n;++j){
			dis[j] = 0x3FFFFFFFFFFFFFF;
			vis[j] = 0;
		}
		qq.push(make_pair(0,x));
		dis[x] = 0;
		while(!qq.empty()){
			int k = qq.top().second;
			qq.pop();
			if(vis[k] == 1){
				continue;
			}
			vis[k] = 1;
			for(int j=h[k];j!=0;j=nxt[j]){
				if(dis[to[j]] > dis[k] + vail[j]){
					dis[to[j]] = dis[k] + vail[j];
					qq.push(make_pair(dis[to[j]],to[j]));
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	
	return 0;
}

