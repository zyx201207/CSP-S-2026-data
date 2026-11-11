#include<bits/stdc++.h>
#define int  long long
using namespace std;
int n,m,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int mx=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,mnd;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)mnd=mid,r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-mnd+1);
	}
	cout<<mx<<"\n";
}
/*
Milky Dragon.
100
*/
