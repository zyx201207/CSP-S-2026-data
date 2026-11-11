#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum[500005];
bool check(int mid,int i){
	int s=a[i]*mid-sum[i]+sum[i-mid];
	return s<=m;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,cnt=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i))cnt=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
