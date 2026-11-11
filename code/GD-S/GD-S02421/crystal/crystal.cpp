#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
#define ll __int128_t
//#define ll long long
//#define cerr if(0)clog
ll ls[500500];
inline ll lget(ll l,ll r){
//	if(l==0)l++;
	return ls[r]-ls[l-1];
}
inline ll myrect(ll l,ll r){
	return (r-l+1)*lget(r,r);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		ls[i]=t;
	}
	sort(ls+1,ls+n+1);
	for(int i=1;i<=n;i++){
		ls[i]+=ls[i-1];
	}
	ll l=1,r=1;
	int ret=0;
	for(;r<=n;r++){
		while(myrect(l,r)-(ll)lget(l,r)>m){
			l++;
		}
		ret=max(ret,(int)(r-l+1));
	}
	cout<<ret;
}
