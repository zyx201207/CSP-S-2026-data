#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL n,m,a[N],b[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++) b[i]=0-a[i];
	for(LL i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
	LL res=0;
	for(LL i=1;i<=n;i++){
		LL cnt=0;
		cnt=sum[i]-i*b[i];
		if(cnt<=m) res=max(i,res);
    }
    cout<<res;
	return 0;
}
