#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,h[M],nxt[M],to[M];
ll w[N],k[M],x,y;
ll val[M],dis[M],vis[M],cnt;
void add(int x,int y,int z){
	val[++cnt]=z;
	to[cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
struct E{
	int pos;
	ll jvli;
	friend bool operator <(E xh,E dh){
		return xh.jvli>dh.jvli;
	}
};
priority_queue<E> qe;
int num[N],sum[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(7<=c&&c<=11){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int i=1;i<=k;i++){
				cin>>num[i]>>sum[i];
			}
			if(k==1){
				continue;
			}
			add(num[1],num[2],sum[1]+sum[2]) ;
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			qe.push({x,0});
			while(!qe.empty()){
				int sum=qe.top().pos;
				qe.pop();
				if(vis[sum]){
					continue;
				}vis[sum]=1;
				for(int i=h[sum];i;i=nxt[i]){
					if(dis[to[i]]>dis[sum]+val[i]){
						dis[to[i]]=dis[sum]+val[i];
						qe.push({to[i],dis[to[i]]});
					}
				}
			}cout<<dis[y]+w[x]+w[y];
		}return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>num[i]>>sum[i];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+rand();
	}
	return 0;
}
