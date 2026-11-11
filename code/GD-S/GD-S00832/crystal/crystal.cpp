#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l=1,r=n,ans=1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(mid*a[mid]-s[mid]>m) r=mid-1;
		else l=mid+1,ans=mid;
	}
	cout<<ans<<"\n";
	return 0;
}
