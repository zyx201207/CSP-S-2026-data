#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
namespace CSPS{
	int n,m;
	int a[500005];
	int he[500005];
	void solve(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)he[i]=he[i-1]+a[i];
		int l=1,ans=1;
		for(int r=2;r<=n;r++){
			while(a[r]*(r-l+1)-he[r]+he[l-1]>m)l++;
			ans=max(ans,r-l+1);
		}
		cout<<ans;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int Q=1;
//	cin>>Q;
	while(Q--)CSPS::solve();
//while(1);
	return 0;
}
/*

1s 1024MB
0.3s 8MB
*/

