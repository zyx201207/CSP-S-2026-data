#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(m==1) cout << a[n];
	else if(m==n) {
		int ans=a[1];
		for(int i=1;i<=n;i++) ans&=a[i];
		cout << ans;
	} else if(m==n-1) {
		int ans=a[2];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout << ans;
	} else if(a[n]<4) {
		if(a[n+1-m]==3) cout << 3;
		else if(a[n+2-m]==2) cout << 2;
		else cout << 0;
	} else if(m==2) {
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) ans=max(1ll*ans,(a[i]&a[j]));
		}
		cout << ans;
	} else {
		cout << a[n+1-m];
	}
	return 0;
}
