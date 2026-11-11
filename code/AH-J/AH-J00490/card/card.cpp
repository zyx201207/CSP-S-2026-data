#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int a2[500030],aa[300030],a[500030],ans[100030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>  n>> m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		a2[i]=a[i];
		}
		
		ll cnt=0;
		ll m1=m;
		while(m>=0){
			for(ll i=1;i<=n;++i){
				a[i]=a2[i];
				aa[i]=0;
		    }
			for(ll i=2;i<=n+cnt+1;++i){
					for(ll j=i-1;j>=1+cnt;--j){
						if(a[i]==0) break;
						if(a[i]==a[j]){
						for(ll p=j;p<=i-1;++p){
								a[p]=0;
							}
							break;
						}
					}
				}
			for(ll i=cnt+1;i<=n;++i){
				if(a[i]>0) aa[a[i]]++;
			}
			for(ll i=1;i<=m1;++i){
				if(aa[i]>0) ans[i]+=1;
			}
			cnt++;
			m--;
		}
		for(ll i=1;i<=m1;++i) cout<<ans[i]<<" ";
		
	return 0;
	
}
