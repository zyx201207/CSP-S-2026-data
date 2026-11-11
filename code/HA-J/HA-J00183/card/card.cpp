#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> c(n+1),ans(m+1);
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	for(int i=1; i<=n; i++) {
		vector<int> lis(n+1);
		for(int j=i; j<=n; j++) {
			lis[j]=c[j];
			int b=0;
			for(int k=0; k<=j-1; k++) {
				if(lis[k]==c[j]) {
					b=1;
				}
				if(b==1) {
					lis[k]==0;
				}
			}
		}
		for(int j=1; j<=n; j++) {
			ans[lis[j]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}

