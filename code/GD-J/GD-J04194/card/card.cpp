#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define M 300005
using namespace std;
ll n,m,a[N],b[N],t[N],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(ll i=1;i<=n;++i)t[i]=a[i];
	for(ll i=1;i<=n;++i){
		for(ll j=i;j<=n;++j){
			ll o=t[j],oo=0,p=0;
			for(ll k=1;k<=n;++k){
				if(a[k]==o){
					p=k;
					break;
				}
			}
			if(p){
				for(ll k=p+1;k<=n;++k){
					a[k]=0;
				}
			}
			else{
				for(ll k=1;k<=n;++k){
					if(!a[k]){
						a[k]=o;
						break;
					}
				}
			}
		}
		memset(b,0,sizeof b);
		for(ll j=1;j<=n;++j){
			b[a[j]]=1;
			a[j]=t[j];
		}
		for(ll j=1;j<=m;++j)ans[j]+=b[j];
	}
	for(ll i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
