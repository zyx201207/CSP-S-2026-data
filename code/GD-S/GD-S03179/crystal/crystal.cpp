#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e6+10,inf=1e18+10;
LL m,n,a[N],maxn=-inf,minn=inf,sum[N];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	LL ans=-1;
	for(int i=1;i<=n;i++){
		LL l=i-1,r=n+1;
		while(l<=r){
			LL mid=(l+r)/2;
			if(a[mid]*(mid-i+1)-(sum[mid]-sum[i-1])>m){
				r=mid-1;
			}
			else if(a[mid]*(mid-i+1)-(sum[mid]-sum[i-1])==m) l=mid+1;
			else l=mid+1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans;
}
//5 5
//1 2 4 8 9


