#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct hh{
	int v;
	ll w;
};
const int N=5e5+5;
int c,n,m,d,q;
ll ck_zt[N];
vector<hh> h[N];
ll dis[N];
int a[N];
ll t[N];
ll dn,mn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ck_zt[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				h[a[j]].push_back({a[l],t[j]+t[l]});
				h[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	while(q--){
		int qd,zd;
		cin>>qd>>zd;
		mn=LLONG_MAX;
		dn=ck_zt[qd]+ck_zt[zd];
		memset(dis,0x3f,sizeof dis);
		dis[qd]=0;
		queue<hh> q_;
		q_.push({qd,0});
		while(!q_.empty()){
			hh ls=q_.front();
			q_.pop();
			int u=ls.v;
			ll w=ls.w;
			for(hh lss:h[u]){
				int v=lss.v;
				ll w=lss.w;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					q_.push({v,dis[v]});
				}
			}
		}
		cout<<dis[zd]+dn<<'\n';
	}
	return 0;
}
/*
4 1 9 2 5
不是我真的能赢吗？
1<->2 12
1<->4 10
2<->4 13
2<->3 7
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
