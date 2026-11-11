#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],mx=1;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=2;
	long long sum=0;
	while(r<=n){
		if(a[r]==a[r-1]){
			long long len=r-l+1;
			mx=max(len,mx);
			r++;
			continue;
		}
		long long len=r-l;
		long long cha=a[r]-a[r-1];
		long long su=cha*len+sum;
		while(su>m){
			su=su-a[r]+a[l];
			l++;
		}
		len=r-l+1;
		sum=su;
		mx=max(len,mx);
		r++;
	}
	printf("%lld",mx);
	return 0;
}
