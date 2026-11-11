#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int r=2;r<=n;r++){
		while((r-l)*(a[r]-a[r-1])>m){
			m+=a[r-1]-a[l];
			l++;
		}
		m-=(r-l)*(a[r]-a[r-1]);
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
