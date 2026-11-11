#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500005;
int n,m,a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=i+1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]*(mid-i+1)-(b[mid]-b[i-1])<=m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i);
	}
	cout<<ans;
}
