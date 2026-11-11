#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct part{
	ll st,ed;
	char c;
};bool cmp(const part & a,const part & b){
	return a.st<=b.st;
}signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	ll fans=0;
	cin>>n;
	vector<part>a;
	for(int i=0;i<n;i++){
		ll x;
		char c;
		cin>>x>>c;
		fans+=x;
		if(!i)a.push_back({1,x,c});
		else if(c==a.back().c)a.back().ed+=x; 
		else a.push_back({a.back().ed+1,a.back().ed+x,c});
	}ll csum=fans;
	fans/=2;
	ll hsum=fans;
	for(size_t i=0;(i<a.size())&&a[i].st<=hsum;i++){
		part c=a[i];
		c.ed=min(c.ed,hsum);
		part d;
		d.st=(csum+1-c.ed),d.ed=(csum+1-c.st);
		ll ds=d.st,de=d.ed;
		auto it=lower_bound(a.begin(),a.end(),d,cmp);
		for(int j=it-a.begin()-1;j>=0&&a[j].ed>=hsum;j--){
			if(a[j].ed<ds)break;
			if(a[j].st<de&&a[j].c==c.c)fans-=min(de,a[j].ed)-max(ds,a[j].st)+1;
		}for(;it!=a.end()&&it->st<=de;it++)if(it->ed>ds&&it->c==c.c)fans-=min(de,it->ed)-max(ds,it->st)+1;
	}cout<<fans<<'\n';
	return 0;
}
