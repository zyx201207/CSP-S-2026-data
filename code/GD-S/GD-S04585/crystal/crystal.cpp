#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll s[500005];
ll n,m;
bool check(int i,int x){
	ll ans=0;
	int cnt=1;
	for(int j=i;j<x;j++){
		ans+=(a[j+1]-a[j])*cnt;
		cnt++;
	}
	if(ans<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll last=1;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	
	//#13-15
	bool f1=true,f2=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f1=false;
		}
		if(i!=1&&i!=n&&a[i]-a[i-1]!=a[i+1]-a[i]){
			f2=false;
		}
		if(!f1&&!f2)break;
	}
	if(f1&&n>5000){
		ll tmp=sqrtl(m*2);
		for(ll i=tmp+50;i>=tmp-50&&i>=1;i--){
			if((1+i)*i/2<=m)return cout<<i,0;
		}
		return 0;
	}
	
	//#16-18
	
	if(f2&&n>5000){
		ll dis=a[2]-a[1];
		ll tmp=m/dis;
		ll tmp1=sqrtl(tmp*2);
		for(ll i=tmp1+50;i>=tmp1-50&&i>=1;i--){
			if((1+i)*i/2*dis<=m&&i<=n)return cout<<i,0;
		}
		return 0;
	}
	
	
	for(int i=1;i<=n;i++){
		int l=i+last,r=n;
		ll mid=l+r>>1,an=-1;
		if(!check(i,l))continue;
		while(l<r){
			mid=l+r>>1;
			if(l==mid||r==mid)break;
			if(check(i,mid))l=mid,an=max(an,mid);
			else r=mid;
			
		}
		last=max(last,an-i+1);
	}
	printf("%lld\n",last);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
