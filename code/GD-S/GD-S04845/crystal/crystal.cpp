#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001];
int sum[1000001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>m)continue;
		int l=1,r=n-1,tans=n-1;
//		for(int mid=l;mid<=r;mid++){
//			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
//				tans=min(tans,mid);
//			}
//		}
		while(l<r){
			int mid=l+r>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
				r=mid;
				tans=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-tans+1);
	//	cout <<i<<' '<<i-tans+1<<'\n';
	}
	cout <<ans;
	return 0;
}
