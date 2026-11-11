#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,l,r,ans,q,k,w[500005],t[1000005];
signed main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k*2;j++)cin>>t[j];
	}
	for (int i=1;i<=q;i++){
		cin>>l>>r;
		for (int j=1;j<=r/2*2;j++)ans+=t[1];
		ans+=w[l];
		ans+=w[r];
		cout<<ans<<endl;
	}
	return 0;
}
