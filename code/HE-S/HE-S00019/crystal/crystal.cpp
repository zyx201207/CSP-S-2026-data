#include <bits/stdc++.h>
using namespace std;
const long long N=500009;
long long n,m,a[N],b[N],ans,l,r,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		l=1,r=i-1;
		while(l<=r){
			mid=l+(r-l)/2;
			if((i-mid)*a[i]-(b[i-1]-b[mid-1])<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
