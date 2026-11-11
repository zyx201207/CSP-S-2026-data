#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,M=3e5+10;

ll n,m,a[N],b[M],cnt[M],ans[M],d;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		b[a[i]]=i,++cnt[a[i]],++ans[a[i]];
	}
	
	for(ll i=n-1;i>=1;--i){
		if(b[a[i]]==i){
			++d;ll j=i;
			while(j<=n){
				if(b[a[j]]==j)++j;
				else j=b[a[j]]+1;
				ans[a[j]]+=cnt[a[i]];
			}
		}
		if(d>=m)break;
	}
	
	for(ll i=1;i<=m;++i)
		printf("%lld ",ans[i]);
	
	return 0;
}  
