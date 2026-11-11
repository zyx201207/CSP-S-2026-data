#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,maxn=0,k;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	k=a[1]&a[2];
	for(ll i=3;i<=n;i++){
		k&=a[i];
	}
	if(m==n) maxn=k;
	else if(m==2){
		maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}else if(m==3){
		maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll kk=j+1;kk<=n;kk++){
					maxn=max(maxn,a[i]&a[j]&a[kk]);
				}
			}
		}
	}else if(m==4){
		maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll kk=j+1;kk<=n;kk++){
					for(ll kkk=kk+1;kkk<=n;kkk++){
						maxn=max(maxn,a[i]&a[j]&a[kk]&a[kkk]);
					}
				}
			}
		}
	}else if(m==5){
		maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll kk=j+1;kk<=n;kk++){
					for(ll kkk=kk+1;kkk<=n;kkk++){
						for(ll kkkk=kkk+1;kkkk<=n;kkkk++){
							maxn=max(maxn,a[i]&a[j]&a[kk]&a[kkk]&a[kkkk]);
						}
					}
				}
			}
		}
	}else if(m==5){
		maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll kk=j+1;kk<=n;kk++){
					for(ll kkk=kk+1;kkk<=n;kkk++){
						for(ll kkkk=kkk+1;kkkk<=n;kkkk++){
							for(ll kkkkk=kkkk+1;kkkkk<=n;kkkkk++){
								maxn=max(maxn,a[i]&a[j]&a[kk]&a[kkk]&a[kkkk]&a[kkkkk]);
							}
						}
					}
				}
			}
		}
	}
	
	cout<<maxn;
	
	
	return 0;
}
