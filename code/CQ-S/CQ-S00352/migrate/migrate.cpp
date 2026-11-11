#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+6;
int c,t,n,d;
ll x[N];
struct hh{
	int u;
	ll w;
};
vector<int> h[N];
int cx[N];
ll dis[N];
int pd[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			h[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d){
					break;
				}
				h[i].push_back(j);
				h[j].push_back(i);
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof dis);
			memset(pd,0x3f,sizeof pd);
			dis[i]=0;
			queue<hh> q;
			q.push({i,0});
			while(!q.empty()){
				hh ls=q.front();
				q.pop();
				int u=ls.u;
				ll w=ls.w;
				for(int v:h[u]){
					if(dis[u]+1<dis[v]){
						dis[v]=dis[u]+1;
						q.push({v,dis[v]});
					}
				}
			}
			pd[i]=0;
			queue<hh> qq;
			qq.push({i,0});
			while(!qq.empty()){
				hh ls=qq.front();
				qq.pop();
				int u=ls.u;
				ll w=ls.w;
				for(int v:h[u]){
					//cout<<u<<' '<<v<<' '<<dis[v]<<' '<<pd[u]<<'\n';
					if(pd[u]+1<pd[v]){
						pd[v]=pd[u]+1;
						qq.push({v,dis[v]});
					}else if(pd[u]+1==dis[v]){
						cx[v]++;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cx[j]==1){
					cnt++;
				}
				cx[j]=0;
			}
			//cout<<"--\n";
		}
		cout<<cnt<<'\n';
		//cout<<"---------\n";
	}
	return 0;
}
/*
这个题目叽里咕噜讲了个啥？
还要刚好两条！？
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 

0 2
5 3
-2 -1 0 1 2 
6 2
-4 -3 -2 -1 3 6
*/ 
