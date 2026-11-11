#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll dsum[N];
ll ans=-1;
bool ck(ll d){
	ll rt=m,i=d,t=1;
	while(rt>=0&&i>0){//n
		if(rt>=a[d]-a[i]){
			rt=rt-a[d]+a[i];
			--i,++t;
		}
		else{
			ans=max(ans,t); 
			return t>=d;
		} 
	}
	return i==0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int st=time(0);
//	ll 4e18;

	cin>>n>>m;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	
	bool flag=false;
	for(ll i=1;i<=n;++i){
		dsum[i]=dsum[i-1]+(i-1)*(a[i]-a[i-1]);	
		if(dsum[i]<dsum[i-1]){
			flag=true;
			break;
		}
//		cout<<dsum[i]<<' ';
	}
	
	if(flag||n>93007){
		ll l=0,r=n+1;
		while(r-l>1){//[)    logn
			ll mid=l+(r-l>>1);
			if(ck(mid))
				l=mid;
			else r=mid;
		}
		cout<<l;
	}
	else{
		for(ll d=n;d>0;--d)
			for(ll i=0;i+d<=n;++i)
				if(dsum[i+d]-dsum[i]<=m){
					cout<<d;
					return 0;	
				}
				
	}
	
 return 0;
} 
/*
5 1
1 100 100 100 100
*/
