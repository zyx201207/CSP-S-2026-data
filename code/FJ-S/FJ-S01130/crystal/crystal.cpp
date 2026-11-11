#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int N=5e5+5;
int n,m,a[N],sum[N],ans=1;

bool check(int k){
	for(int i=1,j=k;j<=n;i++,j++){
		int tmp=k*a[j];
		if(tmp-(sum[j]-sum[i-1])<=m)
			return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	cout << ans;
	return 0;
}
