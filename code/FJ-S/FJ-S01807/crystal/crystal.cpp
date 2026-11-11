#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
const int N=5e5+5;
int n,m,a[N],sum[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int num=(x-1)*a[i]-(sum[i-1]-sum[i-x]);
		if(num<=m)return true;
	}
	return false;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	int l=1,r=n,mid;
	int ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}