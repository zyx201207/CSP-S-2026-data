#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],s[N],idx,ans,cnt,cnt2,idn;
bool cmp(ll x,ll y){
	return x<y;
}
ll f(int x,int z){
	ll zuo=(z-x+1)*a[z]-(s[z]-s[x-1]);
	return zuo;
}
ll find(int l,int r,int q){
	while(l<r){
		int mid=(l+r)>>1;
		if(f(q,mid)>m) r=mid-1;
		else if(f(q,mid)<=m) l=mid+1;
	}
	if(f(q,l)>m) return l-1;
	else return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(a[1]<0) idx=abs(a[1]);
	for(int i=1;i<=n;i++){
		a[i]+=idx;
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		int ss=find(i+1,n,i);
		ll kk=ss-i+1;
//		cout<<kk<<" "<<i<<" "<<ss<<endl;
		if(f(i,ss)<=m) idn=1;
		ans=max(ans,kk);
	}
	if(idn==0) cout<<1;
	else cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
