#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		int l(1),r(i);
		while(l<r){
			int mid((l+r)>>1);
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return 0;
} 
