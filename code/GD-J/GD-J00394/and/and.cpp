#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		int x;
		for(int j=1;j<=m;j++){
			x=a[i+1]&a[i];
		}
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
