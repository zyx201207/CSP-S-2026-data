#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
int sum[500005];
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l,r,ans=0;
	for(int i=n;i>=1;i--){
		l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
