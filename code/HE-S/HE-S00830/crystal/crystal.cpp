#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,tmaxx,a[100005];
map<ll,ll> js;
bool bj;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		tmaxx=max(tmaxx,a[i]);
		js[a[i]]++;
		if(a[i]!=a[i-1]+1&&i!=1) bj=1; 
	}
	if(n<=5000){
		ll maxx=-1e12;
		ll cnt=1;
		ll mm=m;
		for(ll i=1;i<=n;i++){
			sort(a+1,a+i,cmp);
			mm=m;
			cnt=1;
			for(ll j=i-1;j>=1;j--){
				if(mm<0) break;
				if((mm-abs(a[i]-a[j]))>=0){
					mm=mm-abs(a[i]-a[j]);
					cnt++;
				}else break;
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
	}else if(tmaxx<=100){
		ll maxx=-1e12;
		for(ll i=1;i<=100;i++){
			if(!js[i]){
				ll cnt=0;
				ll mm=m;
				for(ll j=1;j<=n;j++){
					if(mm<0) break;
					if(a[j]<=i){
						if(mm-(abs(a[j]-i))>=0){
							mm=mm-abs(a[j]-i);
							cnt++;
						}else break;
					}
				}
				maxx=max(maxx,cnt);
			}
		}
		cout<<maxx;
	}else if(!bj){
		ll cnt=1;
		ll mm=m;
		for(ll i=n-1;i>=1;i--){
			if(mm<=0) break;
			if(mm>0){
				mm--;
				cnt++;
			}else break;
		}
		cout<<cnt;
	}else{
		ll cnt=1;
		ll mm=m;
		for(ll i=n-1;i>=1;i--){
			if(mm<0) break;
			if(mm-(a[n]-a[i])>=0){
				mm=mm-(a[n]-a[i]);
				cnt++;
			}else break;
		}
		cout<<cnt;
	}
	return 0;
}
