#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum[500005];
bool cmp(int x,int y) {
	return x>y;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	bool f=1;
	for(int i=1; i<=n-2; i++) if(a[i+1]-a[i]!=a[i+2]-a[i+1]) f=0;
	if(f) {
		int d=a[2]-a[1];
		m=m/d;
		for(int i=1; i<=n; i++) {
			if(m-i>=0) ans++;
			else break;
		}
		cout<<ans;
	} else {
//		cout<<"sum:";
		for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i]/*,cout<<sum[i]<<' '*/;
//		cout<<'\n'<<'\n';
		for(int i=1; i<=n; i++) {
			for(int j=n; j>=i; j--) {
				if((j-i+1)*a[i]-sum[j]+sum[i-1]<=m) {
					//cout<<"cost:"<<(j-i+1)*a[i]-sum[j]+sum[i-1]<<'\n';
					ans=max(ans,j-i+1);
					//cout<<"i:"<<i<<' '<<"j:"<<j<<'\n';
					//for(int k=i; k<=j; k++) cout<<a[k]<<' ';
					//cout<<'\n'<<'\n';
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
