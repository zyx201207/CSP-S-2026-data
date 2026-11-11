#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],ans[300005],mxp[300005],n,m;
int main(){
	//freopen("card6.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf(" %lld",a+i);
		mxp[a[i]]=i;
	}
	for(ll ju=1;ju<=n;ju++){
		ll pos=ju;
		for(ll i=ju;i<=n;i++){
			if(mxp[a[i]]!=i){
				for(int j=pos;j<i;j++) ans[a[j]]++;
				i=mxp[a[i]];
				pos=i;
			}
		}
		//cerr<<pos<<"\n";
		for(ll i=pos;i<=n;i++) ans[a[i]]++;
		//for(int i=1;i<=m;i++) cerr<<ans[i]<<" ";
		//cerr<<"\n";
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
