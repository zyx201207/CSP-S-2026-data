#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,q,d,w[1000000],k[1000000],dis[100005],ans[1000000],vis[1000000],cntt;
pair<ll,ll>z;
ll head[1000000],tot;
struct nood{
	ll v,nxt,w;
}e[1000000];
struct nod{
	ll A,t;
}a[1000000];
struct nd{
	ll x,y,id;
}Q[1000000];
void adde(ll x,ll y,ll z){
	e[++tot].v=y,e[tot].nxt=head[x],e[tot].w=z,head[x]=tot;
}
void dij(ll x){
	cntt++;
	vis[x]=cntt;
	dis[x]=0;
	priority_queue<pair<ll,ll>>qu;
	qu.push({0,x});
	while(!qu.empty()){
		ll di=qu.top().second;
		ll z=-qu.top().first;
//		cout<<di<<":"<<z<<"?\n";
		qu.pop();
//		cout<<dis[di]<<"?????";
		if(dis[di]==z){
//			cout<<"???";
			for(int i=head[di];i;i=e[i].nxt){
				ll v=e[i].v;
//				cout<<"v:"<<v<<endl;
				if(vis[v]!=cntt){
					vis[v]=cntt;
					dis[v]=1e18;
				}
				if(dis[v]>dis[di]+e[i].w){
					dis[v]=dis[di]+e[i].w;
					qu.push({-dis[v],v});
				}
			}
		}
	}
}
bool cmp(nd X,nd Y){
	return X.x<Y.x;
}
int main(){
//	priority_queue<ll>qu;
//	qu.push(1);
//	qu.push(0);
//	qu.push(2);
//	cout<<qu.top();

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	if(c<=15){
		for(int i=1;i<=m;i++){
			scanf("%lld",&w[i]);
		}
//		cout<<"?\n";
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%lld%lld",&a[j].A,&a[j].t);
//				cin>>a[j].A>>a[j].t;		
			}
			for(int j=1;j<=k[i];j++){
				for(int o=j+1;o<=k[i];o++){
//					cout<<a[j].A<<"->"<<a[o].A<<":"<<a[j].t+a[o].t<<endl;
					adde(a[j].A,a[o].A,a[j].t+a[o].t);
					adde(a[o].A,a[j].A,a[j].t+a[o].t);
				}
			}
//			cout<<"ok"<<i<<":\n";
		}
//		cout<<"?\n";
		for(int i=1;i<=q;i++){
			scanf("%lld%lld",&Q[i].x,&Q[i].y);
//			cin>>Q[i].x>>Q[i].y;
			Q[i].id=i;
		}
		sort(Q+1,Q+q+1,cmp);
		ll now=0;
//		cout<<q<<"????\n";
		for(int i=1;i<=q;i++){
			now=Q[i].x;
//			cout<<i<<"?\n";
			dij(now);
			ans[Q[i].id]=dis[Q[i].y]+w[Q[i].x]+w[Q[i].y];
			while(Q[i+1].x==now){
				i++;
				ans[Q[i].id]=dis[Q[i].y]+w[Q[i].x]+w[Q[i].y];
				if(i>q){
					break;
				}
			}
		}
		for(int i=1;i<=q;i++){
			cout<<ans[i]<<"\n";
		}
//	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
