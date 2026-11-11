#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],b[M],bw[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(bw,0,sizeof bw);
		for(ll j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(ll k=bw[a[j]];k<=j-1;k++){
					b[a[k]]=0;
					bw[a[k]]=0;
				}
			}
			b[a[j]]=1;
			bw[a[j]]=j;
		}
		for(ll j=1;j<=m;j++) ans[j]+=b[j];
	}
	for(ll i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
