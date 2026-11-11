#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define H <<' '<<
using namespace std;
ll n,a[200005],a1[200005],a2[200005],p,ns;
char c[200005],c1[200005],c2[200005],d[3];
vector<pair<ll,pair<ll,char>>> v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
//	freopen("string/string6.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		p+=a[i];
	}
	p=p/2;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(i==1){
			a1[i]=0;
		}else{
			a1[i]=a1[i-1]+a[i-1];
		}
		c1[i]=c[i];
		v.push_back({a1[i],{1,c1[i]}});
	}
	reverse(a+1,a+1+n);
	reverse(c+1,c+1+n);
	for(ll i=1;i<=n;i++){
		if(i==1){
			a2[i]=0;
		}else{
			a2[i]=a2[i-1]+a[i-1];
		}
		c2[i]=c[i];
		v.push_back({a2[i],{2,c2[i]}});
	}
	sort(v.begin(),v.end());
//	for(auto i:v){
//		cout<<"A" H i.first H i.second.first H i.second.second<<'\n';
//	}
	d[1]=v[0].second.second;
	d[2]=v[1].second.second;
	for(ll i=2,t=0;i<v.size();i++){
		ll tt=v[i].first;
		tt=min(tt,p);
		if(d[1]!=d[2]){
			ns+=tt-t;
		}
		d[v[i].second.first]=v[i].second.second;
		t=tt;
		if(v[i].first>=p){
			break;
		}
	}
	cout<<ns;
	return 0;
}
// 100
