#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],pre[N],ans;
bool check(ll len){
	FOR(i,len,n){
		if(len*a[i]-(pre[i]-pre[i-len])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,n)pre[i]=pre[i-1]+a[i];
	ll l=1,r=n,mid=0;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
