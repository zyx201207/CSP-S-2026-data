#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct island{
	ll p,dis;
};
ll minpath(const vector<ll> &a,ll d,ll x1,ll x2){
	queue<island> q;
	ll mi=LLONG_MAX;
	island t;
	t.p=x1;
	t.dis=0;
	q.push(t);
	while(!q.empty()){
		island h=q.front();
		q.pop();
		if(h.p==x2){
			mi=min(mi,h.dis);
			continue;
		}
		for(ll i=h.p+1;i<a.size();i++){
			if(a[i]-a[h.p]<=d){
				island nw;
				nw.p=i;
				nw.dis=h.dis+1;
				q.push(nw);
			}
		}
	}
	return mi;
}
bool twin(const vector<ll> &a,ll d,ll x1,ll x2){
	queue<island> q;
	ll c=0;
	island t;
	t.p=x1;
	t.dis=0;
	q.push(t);
	while(!q.empty()){
		island h=q.front();
		q.pop();
		if(h.p==x2&&h.dis==minpath(a,d,x1,x2)){
			c++;
			continue;
		}
		for(ll i=h.p+1;i<a.size();i++){
			if(a[i]-a[h.p]<=d){
				island nw;
				nw.p=i;
				nw.dis=h.dis+1;
				q.push(nw);
			}
		}
	}
	return c==2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		vector<ll> a;
		ll n,d;
		cin>>n>>d;
		while(n--){
			ll x;
			cin>>x;
			a.push_back(x);
		}
		ll c=0;
		for(int i=0;i<a.size();i++){
			for(int j=i+2;j<a.size();j++){
				if(twin(a,d,i,j)) c++;
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}
