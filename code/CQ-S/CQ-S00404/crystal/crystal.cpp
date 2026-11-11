#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN],sum[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int answ=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=1e9;
		while(l<=r){
			int mid=(l+r)/2;
			if((a[i]*(i-mid+1))-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		answ=max(answ,i-ans+1);
	}
	printf("%lld",answ);
	return 0;
}
 
