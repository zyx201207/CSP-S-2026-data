#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ans=-1,n,m,a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long sum=0,s=1;
		for(int j=i-1;j>=1;j--){
			sum=sum+a[i]-a[j];
			if(sum>m) break;
			s++;
		}
		ans=max(ans,s);
	}
	printf("%lld",ans);
	return 0;
}
