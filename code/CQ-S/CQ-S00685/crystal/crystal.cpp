#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
