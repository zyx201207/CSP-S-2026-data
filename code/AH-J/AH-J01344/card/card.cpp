#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],ans[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(n>10000)
	{
		for(int i=1;i<=m;i++) {
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		int cnt=0;
		for(int j=i;j<=n;j++) {
			t[++cnt]=a[j];
			int tmp=0,k=1;
			for(;k<cnt;k++) {
				if(t[k]==t[cnt]) {
					tmp=1;
					break;
				}
			}
			if(tmp==1) {
				cnt=k;
			}
		}
		for(int j=1;j<=cnt;j++) {
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
