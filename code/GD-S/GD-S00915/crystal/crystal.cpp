#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans;
int check(int x){
	for(int i=x;i<=n;i++){
		int num=(a[i]-a[i-1])*x,sum=a[i]-a[i-x];
		if(num-sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
}
