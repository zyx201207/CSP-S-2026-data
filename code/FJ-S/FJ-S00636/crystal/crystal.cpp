#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(sum[i]+m>=i*a[i]){ans=max(ans,i);continue;}
		int l=1,r=i,md;
		while(l<=r){
			md=(l+r)>>1;
			if(a[i]*(i-md+1)-(sum[i]-sum[md-1])<=m){
				r=md-1;
			}else l=md+1;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
