#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		long long cnt=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++){
			long long cnt1=0,cnt2=0,it=0;
			for(int j=1;j<=n;j++){
				if(a[i]+d<a[j])break;
				if(a[i]+d==a[j])cnt1++,it=j;
				if(cnt1>1)break;
			}
			if(cnt1!=1)continue;
			for(int j=1;j<=n;j++){
				if(a[it]+1<a[j])break;
				if(a[it]+1==a[j])cnt2++;
				if(cnt2>1)break;
			}
			if(cnt2!=1)continue;
			cnt1=0,cnt2=0,it=0;
			for(int j=1;j<=n;j++){
				if(a[i]+1<a[j])break;
				if(a[i]+1==a[j])cnt1++,it=j;
				if(cnt1>1)break;
			}
			if(cnt1!=1)continue;
			for(int j=1;j<=n;j++){
				if(a[it]+d<a[j])break;
				if(a[it]+d==a[j])cnt2++;
				if(cnt2>1)break;
			}
			if(cnt2!=1)continue;
			cnt++;
		}
		printf("%lld\n",cnt);
	} 
	return 0;
}
