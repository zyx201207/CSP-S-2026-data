#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,a[N],sum[N],ans,l,r;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	} 
	l=1,r=sum[n];
	while(l<r){
		long long x=lower_bound(sum+1,sum+n+1,l)-sum;
		long long y=lower_bound(sum+1,sum+n+1,r)-sum;
		long long z=min(sum[x]-l+1,r-sum[y-1]);
		if(x==y) break;
		if(c[x]!=c[y]) ans+=z;
		l+=z;
		r-=z;
	}
	cout<<ans;
	return 0;
}
