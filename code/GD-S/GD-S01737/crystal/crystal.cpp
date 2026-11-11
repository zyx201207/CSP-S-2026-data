#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long sum[500005];
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-sum[i-1]+sum[mid-1]<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0; 
} 
