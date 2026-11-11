#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
int n,m,a[maxn],diff[maxn],sum[maxn],cnt=0;
int check(int x){
	int cnt=1e18;
	for(int i=1;i<=(n-x+1);i++){
		int w=a[i+x-1]*x-(sum[i+x-1]-sum[i-1]);
		cnt=min(cnt,w);
	}
	return cnt;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int l=0,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)<=m){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
