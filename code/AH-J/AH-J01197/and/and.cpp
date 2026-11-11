#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+1;
struct node{
	ll x,g;
}a[N];
ll n,m,he;
string tto(ll shu){
	string d;
	while(shu){
		shu/=2;
		ll t=shu%2;
		d+=char(t+'0');
	}
	reverse(d.begin(),d.end());
	return d;
}
ll tj(string c){
	ll cnt=0;
	for(int i=0;i<c.size();i++){
		if(c[i]=='1')cnt++;
	}
	return cnt;
}
bool cmp(node e,node f){
	if(e.g!=f.g)return e.g>f.g;
	return e.x>f.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].g=tj(tto(a[i].x));
	}
	sort(a+1,a+n+1,cmp);
	he=a[1].x;
	for(int i=2;i<=m;i++){
		he=(he&(a[i].x));
	}
	cout<<he;
	return 0;
}
