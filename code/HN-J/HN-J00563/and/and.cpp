#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2*1e5+5;
int a[N];

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int cnt=a[i]&a[j];
			ans=max(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}
