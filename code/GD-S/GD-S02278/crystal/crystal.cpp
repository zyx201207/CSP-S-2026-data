#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010],c[500010];
struct oh{
	ll h,t,c;
}l[500010];
bool cmp(oh a,oh b){
	return a.c>b.c;
}
ll len(ll h,ll t){
	ll ma=1;
	for(ll i=h;i<=t;i++){
		ll sum=0;
		for(int k=i;k<=t;k++){
			sum+=c[k]*(k-i+1);
			if(sum<=m){
				ma=max(ma,k-i+1);
			}
		}
	}
	return ma;
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	ll x=1;
	l[x].h=1;
	l[x].t=0;
	for(int i=1;i<=n;i++){
		l[x].t++;
		l[x].c=l[x].t-l[x].h+1;
		if(c[i]>m){
			x++;
			l[x].h=i+1;
			l[x].t=i;
		}
	}
	sort(l+1,l+1+x,cmp);
	ll ans=0;
	for(int i=1;i<=x;i++){
		ans=max(ans,len(l[i].h,l[i].t));
	}
	cout<<ans<<"\n";
	return 0;
} 
