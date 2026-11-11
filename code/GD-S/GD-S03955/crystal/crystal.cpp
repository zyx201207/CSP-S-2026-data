#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool cmp(long long x,long long y){
	return x>y;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++){
		long long sum=0,l=i,r=n;
		while(l<=r){
			long long mid=(l+r)>>1;
			if((mid-i+1)*(a[i]-a[i-1])-(a[mid]-a[i-1])<=m)sum=(mid-i+1),l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
} 
