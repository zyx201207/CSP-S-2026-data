#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,m,ans,sum[500005];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int p=x*a[x+i-1]-sum[x+i-1]+sum[i-1];
		if(p<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
