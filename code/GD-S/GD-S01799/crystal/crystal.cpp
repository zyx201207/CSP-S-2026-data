#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,l,r,mid,no;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		l=i,r=n,no=0;
		while(l<=r){
			mid=(l+r)/2;
			if((mid-i+1)*(a[mid]-a[mid-1])-(a[mid]-a[i-1])<=m){
				no=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,no-i+1);
	}
	cout<<ans<<endl;
	return 0;
} 
