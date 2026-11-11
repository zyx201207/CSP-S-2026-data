#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,n,m,a[500005],res,pre[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1;
	for(int r=1;r<=n;r++){
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
