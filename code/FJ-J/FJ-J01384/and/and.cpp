#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,ma;
signed main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout),cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n),ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	ma=ans;
	for(int i=m+1;i<=n;i++){
		int ans=a[i-m+1];
		for(int j=i-m+2;j<=i;j++)ans&=a[i];
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
