#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200005],ans,mx;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	ans=a[1];
	for(int i=2;i<=n;i++) ans&=a[i];
	if(m==1) cout<<mx;
	else if(m==2){
		int mxans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int lll=a[i]&a[j];
				mxans=max(mxans,lll);
			}
		}
		cout<<mxans;
	}else if(m==n) cout<<ans;
	ans=0;
	return 0;
}
