#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550,M=5e5+5;
int c,n,m,d,q; //n:地铁线路数  m:地铁站数  d:每个地铁站最多被几条线路经过  q: 出行计划数
int w[N],k;  //w:口->厅 
struct node{
	int s,t;  //a[i].t:厅->台 
}a[M];
int x,y;
bool f=true;
ll T;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(n--){
		cin>>k;
		if(k!=2) f=false;
		for(int j=1;j<=k;j++){
			cin>>a[j].s>>a[j].t;
			T=a[j].t;
		} 
	}
	while(q--){
		ll ans=0;
		cin>>x>>y;
		ans=ans+w[x]+w[y]+2*T;
		cout<<ans;
	}
	return 0;
}
