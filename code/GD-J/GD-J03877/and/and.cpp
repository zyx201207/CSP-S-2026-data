#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ws(ll x){
	ll sum=0;
	while(x>0){
		x/=2;
		sum++;
	}
	return sum;
}
ll bx(ll x){
	ll sum=1;
	while(x>=1){
		x--;
		sum*=2;
	}
	return sum;
}
ll n,m,maxn,ac=1,a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)
			ac=0;
	}
	sort(a+1,a+n+1);
	if(ac==0)
		cout<<a[n-m+1];
	else{
		ll w=ws(a[n]);
		ll jg=a[n]-bx(w)+1;
		if(jg>=m){
			cout<<a[n];
		}
		else{
			jg=bx(w);
			w--;
			jg-=bx(w);
			if(jg>=m){
				for(int i=w-m+1;i>=1;i--){
					cout<<1;
				}
				for(int i=m-1;i>=1;i--){
					cout<<0;
				}
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
}
