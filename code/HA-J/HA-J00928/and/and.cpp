#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans=0;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=a[i];
			x&=a[i+1];
			ans=max(ans,x);
		}
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

