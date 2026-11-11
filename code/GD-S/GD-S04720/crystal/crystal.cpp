#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,k,num;
ll a[500001];
ll maxn(ll x,ll y){
	if(x>y) return x;
	return y;
}
ll absb(ll x){
	if(x<0) return -x;
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool p=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			p=false;
			break;
		}
	}
	if(p){
		k=m;
		ans=1;
		for(int i=1;i<n;i++){
			if(k>=i){
				k-=i;
				ans++;
			}
			if(k<i) break;
		}
	}
	if(!p){
		bool q=true;
		ll s=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=s){
				q=false;
				break;
			}
		}
		if(q){
			k=m;
			ans=1;
			for(int i=1;i<n;i++){
				if(k>=i*s){
					k-=i*s;
					ans++;
				}
				if(k<i*s){
					break;
				}
			}
		}
		if(!q){
			ans=-1;
			for(int i=2;i<=n;i++){
				k=m;
				num=1;
				for(int j=i-1;j>=1;j--){
					if(k>=a[i]-a[j]){
						num++;
						k-=(a[i]-a[j]);
					}
					if(k<a[i]-a[j]) break;
				}
				ans=maxn(ans,num);
			}
		}
	}
	cout<<ans;
	return 0;
}
