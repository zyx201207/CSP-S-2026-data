#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,m,a[N],ans;
bool b[N];
bool check(ll p){
	ll ccc=0;
	for(ll ii=1;ii<=n;++ii){
		if((!b[ii])&&(((a[ii]>>p)&1)==1))++ccc;
	}
	if(ccc>=m)return true;
	else return false;
}
void gai(ll p){
	for(ll ii=1;ii<=n;++ii){
		if(((a[ii]>>p)&1)==0)b[ii]=true;
	}
}
signed main(){//如果check能过，gai必定会剩m以上  被cnt硬控接近一小时 qisiwole 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=32;i>=0;--i){
		if(check(i)){
			gai(i);
			ans+=(1<<i); 
		}
	}
	cout<<ans;
	return 0;
}
