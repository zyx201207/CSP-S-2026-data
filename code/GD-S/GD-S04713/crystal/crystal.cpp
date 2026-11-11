#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int N=1e5*5+5;
long long a[N];
long long check(long long x){
	long long res=1,m1=m;
	for(int i=x-1;i>=1;i--){
		if(m1>=(a[x]-a[i])){
			m1-=a[x]-a[i];
			res++;
		}
//		else{
//			return res;
//		}
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long l=1,r=n,mid=l+((r-l)>>1);
	while(l<=r){
		mid=l+((r-l)>>1);
//		mid=l+(r-l)/2;
		long long t=check(mid);
//		cout<<l<<" "<<r<<endl;
		if(t>=ans){
			ans=t;
			l=mid+1;
		}
		else if(t<ans){
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
} 
