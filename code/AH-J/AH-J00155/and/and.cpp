#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,a[200010],w[40],ans,maxn;
bool f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=ll(log2(a[i]))+1ll;
		ll x=a[i];
		for(int j=30;j>=0;j--){
			if(x>=(1<<j)){
				w[j]++;
				x-=(1<<j);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=maxn;i>=0;i--){
		if(w[i]>=m){
			ans+=(1ll<<i);
			for(int j=1;j<=n;j++){
				if(a[j]<(1ll<<i)&&f[j]==1){
					ll x=a[j];
					for(int j=30;j>=0;j--){
						if(x>=(1<<j)){
							w[j]--;
							x-=(1<<j);
						}
					}
					f[j]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]>=(1ll<<i)){
				a[j]-=(1ll<<i);
				w[i]--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
