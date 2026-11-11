#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll c,n,m,d,q;
ll w[N];
ll dtd[N];
struct sw{
	ll e,t;
};
struct P{
	ll d,ys;
	bool operator<(const P &a)const{
		return ys>a.ys;
	}
};
vector<sw>dt[N];
void f(ll q1,ll q2){
	priority_queue<P>p;
	ll ans=w[q1]+w[q2];
	p.push({q1,0});
	while(p.size()){
		P xz=p.top();
		p.pop();
		//cout<<xz.d<<";";
//		if(dtd[xz.d]!=xz.ys){
//			continue;
//		}
		
		if(xz.d==q2){
			cout<<xz.ys+ans<<endl;
			break;
		}
		ll dtxs=dt[xz.d].size();
		//cout<<dtxs;
		for(ll i=0;i<dtxs;i++){
			ll dtx=dt[xz.d][i].e;
			
			if(dtx==xz.d)continue;
			//cout<<dtx<<"="<<dt[xz.d][0].t<<";";
			p.push({dtx,xz.ys+dt[xz.d][i].t+dt[xz.d][0].t}) ;
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll nn;
		cin>>nn;
		for(ll j=1;j<=nn;j++){
			ll dn,tn;
			cin>>dn>>tn;
			dt[i].push_back({dn,tn});
			//dt[dn].push_back({i,tn});
		}
	}
	for(ll qs=1;qs<=q;qs++){
		ll q1,q2;
		cin>>q1>>q2;
		f(q1,q2);
	}
	
	
	
	return 0;
} 
