#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5,M=3e5+10;
LL n,m,a[N],ans[M];
bool cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(LL i=1;i<=n;i++){
		stack<LL> d;
		for(LL j=i;j<=n;j++){
			LL k=a[j];
			if(cnt[k]==1){
				while(d.top()!=k){
					cnt[d.top()]=0;
					d.pop();
				}
			}else{
				cnt[k]=1;
				d.push(k);
			}
		}
		for(LL i=1;i<=m;i++) ans[i]+=cnt[i];
	}
	for(LL i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
