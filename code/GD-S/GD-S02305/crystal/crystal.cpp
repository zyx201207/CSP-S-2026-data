#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans;
ll a[N],sum[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			ll need=(mid)*1ll*a[i]-(sum[i-1]-sum[i-mid-1]);
			if(need>m){
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(l,ans);
	}
	printf("%d",ans);
	return 0;
} 
/*
Oct31==Dec25?
5 5 
1 2 4 8 9
 
5 8
-3 -1 2 2 7
*/
