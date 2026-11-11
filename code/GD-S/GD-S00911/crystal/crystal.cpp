#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,lx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;j<=n;j++){
		lx+=a[j];
		while(a[j]*(j-i+1)-lx>m&&i<=j)lx-=a[i++];
		ans=max(ans,(j-i+1));
	}
	cout<<ans;
}
