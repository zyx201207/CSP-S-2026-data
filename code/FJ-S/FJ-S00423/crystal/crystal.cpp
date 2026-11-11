#include<bits/stdc++.h>
using namespace std;
const int N=5.1e5;
long long n,a[N],m,sum[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}	
	long long l=1;
	for(long long r=2;r<=n;r++){
		while(l<r){
			long long w=(sum[r]-sum[l-1]+m)/(r-l+1);
			if(w<a[r]){
				l++;
			}else{
				break;
			}
		}
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}
