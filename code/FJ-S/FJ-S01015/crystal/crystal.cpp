#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m;
long long a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}
