#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
struct mode{
	ll net,to,w;
}l[N];
struct point{
	ll pos,wt;
	bool operator>(const point& a)const{return wt>a.wt;}; 
}p[N];
priority_queue<point,vector<point>,greater<point> >s;
ll head[N],cnt;
ll c,n,m,d,q;
ll mm[N],a[N],t[N];
void line(ll u,ll v,ll tt){
	cnt++;
	l[cnt].net=head[u];
	head[u]=cnt;
	l[cnt].to=v;
	l[cnt].w=tt;
}
void mine(){
	for(int i=0;i<n;i++){
		a[i]=INT_MAX;
	}
	ll x,y;
	cin>>x>>y;
	a[x]=0;
	s.push({x,0});
	while(!s.empty()){
		point now=s.top();
		ll ue=now.pos;
		if(t[ue]==1)continue;
		else{
			t[ue]=1;
		}
		for(int i=head[ue];i!=0;i=l[i].net){
			if(a[l[i].to]<a[ue]+l[i].w&&t[l[i].to]!=1){
				a[l[i].to]=min(a[l[i].to],a[ue]+l[i].w);
				s.push({l[i].to,a[i]+l[i].w});
			}
		}
	}
	cout<<a[y]<<endl;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>mm[i];
	}
	for(int i=0;i<n;i++){
		ll k;cin>>k;ll a[2],t[2];
		for(int j=0;i<=k;j++){
			cin>>a[j]>>t[j];
		}
		if(k==2){
			line(a[0],a[1],t[1]+t[0]);
			line(a[1],a[0],t[1]+t[0]);
		}
	}
	while(q--){
		mine();
	}
	return 0;
}
