#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+2;
int m,n,a[N],ans,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,std::greater<>());
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for (int i=1;i<=n;i++){
		int ans2=0;
		int l=1,r=n;
		//(j-i+1)*a[i]-\sum{i-j}a[k].
		while (r>=l){
			int mid=(l+r)/2;
			if ((mid-i+1)*a[i]-(b[mid]-b[i-1])<=m){
				ans2=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,ans2-i+1);
	}
	cout<<ans;
}
/*
4 8
1 1 1 1
*/
