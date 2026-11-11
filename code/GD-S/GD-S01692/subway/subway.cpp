#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
const ll M=1e3+10;
ll c,n,m,d,q;//测试点编号，地铁线路数，地铁站数，地铁站被线路经过数，出行计划数 
ll w[N];//地铁口到站厅时间
ll k[N];//这一条线路经过了多少个站
ll a[N];//第几条线路经过第几个地铁站
ll t[N];//从站厅走到站台的时间
ll x[N],y[N];//出行计划的起点终点的地铁站编号
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	while(q--){
		ll x,y;
		cn>>x>>y;
		if(c==12||c==13||c==14||c==15||c==16||c==17||c==18||c==19){
		     ll T=t[1][1];
		     ll sum=0;
		     for(int i=1;i<=n;i++){
		     	sum+=k[i]*T;
			 }
			 cout<<sum<<endl;
		}
		else{
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
