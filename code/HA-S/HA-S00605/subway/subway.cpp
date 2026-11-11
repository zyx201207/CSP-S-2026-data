#include<bits/stdc++.h>
using namespace std;
struct sub{
	long long s,t;
}a[1000006];
long long c,n,m,d,q1,kk,k[505],kt[500005],x,y,ans,ans1,cnt;
//long long to[1000006],nxt[1000006],b[1000006],va[1000006],dis[1000006],h[1000006];
//
//void add(long long a,long long b,long long c){
//	to[++cnt]=b;
//	va[cnt]=c;
//	nxt[cnt]=h[a];
//	h[a]=cnt;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
//	for(int i=1;i<=n;i++){
//		dis[i]=0x3fffffff;
//	}
	for(int i=1;i<=m;i++){
		cin>>kt[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kk;
		for(int i=1;i<=kk;i++){
			cin>>a[i].s>>a[i].t;
//			if(i!=1) {
//				add(a[i-1].s,a[i].s,a[i-1].t);
//				add(a[i].s,a[i-1].s,a[i].t);
//			}
		}
	}
	for(int i=1;i<=q1;i++){
//		priority_queue<pair<long long,long long> > q;
		cin>>x>>y;
		ans1=kt[x]+kt[y];
//		q.push(make_pair(0,x));
//		dis[x]=0;
//		while(!q.empty()){
//			long long u=q.top().second;
//			q.pop();
//			if(b[u]==1)continue;
//			b[u]=1;
//			for(int j=h[u];j!=0;j=nxt[j]){
//				long long v=to[j];
//				if(dis[u]>(long long)(dis[v]+va[j])){
//					dis[u]=dis[v]+va[j];
//					q.push(make_pair(-dis[v],v));
//				}
//			}
//		}
		cout<<ans1+(a[1].t*(y-x))<<endl;
//		memset(dis,0x3fffffff,sizeof(dis));
	}
	return 0;
}
