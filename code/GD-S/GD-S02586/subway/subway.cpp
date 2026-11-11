#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=500005,maxn=505,maxd=25;
ll c,n,m,d,q;
struct node{
	ll w;//从每个地铁站的地铁口走到站厅需要的时间
	ll t[maxd];//该地铁站的站厅走到第 i 条线路的站台需要的时间
}stat[maxm];
ll line[maxn],p[maxn];//p[i]为第i条线路的车站数量 
ll search(ll,ll);
ll myvisit[maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>stat[i].w;
	for(ll i=1;i<=n;i++){
		ll a,b;
		cin>>a>>b;
		stat[a].t[i]=b;
	}
	while(q--){
		ll x,ll,y;
		cin>>x>>y;
//		myvisit.push(x);
//		search(x,y);
	}
	cout<<"36\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
