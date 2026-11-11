#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int now=0,l=n,z=0;
	for(int r=n;r>=1;r--){
		now-=(r-l+1)*z;
		z=a[r]-a[r-1];
		while(a[r]-a[l]+now<=m&&l>=1){
			now+=a[r]-a[l];
			l--;
		}
		ans=max(ans,r-l);
		if(l==1){
			break;
		}
	}
	cout<<ans;
	return 0;
}