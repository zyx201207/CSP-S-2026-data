#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=5e5+5;
ll m,a[N],sum[N];
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		while(k<i&&a[i]*(i-k+1)-(sum[i]-sum[k-1])>m){
			k++;
		}
		ans=max(ans,i-k+1);
	}
	printf("%d",ans);
	return 0;
} 
