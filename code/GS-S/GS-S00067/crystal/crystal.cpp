#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,res,a[500005],pre[500005];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++)pre[i]=a[i]+pre[i-1];
	int r=1;
	for(int l=0;l<n;l++){
		while(r<=n&&(a[r]*(r-l)-(pre[r]-pre[l]))<=m)res=max(res,r-l),r++;
	}
	cout<<res;
	return 0;
}
