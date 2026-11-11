#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
const int N=500005;
ll a[N],c[N],sum[N],m;int n,ans=1;
ll mxn(int l,int r){
	if(l==r)return 0;
	if(r==l+1)return a[r]-a[l];
	return a[r]*(1ll*r-l+1)-sum[r]+sum[l-1];
}
int main(){
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
 	}
	if(m==0) { cout<<1<<'\n'; exit(0); } 
	sort(a+1,a+n+1);
 	for(int i=1;i<=n;++i){
 		sum[i]=a[i]+sum[i-1];
	} int f1=1,r1=0;
	for(r1=1;r1<=n;++r1){
		while(f1<r1&&mxn(f1,r1)>m)++f1;
		if(f1==r1)continue;
		ans=max(ans,r1-f1+1); 
	} cout<<ans<<'\n';
	return 0;
}
