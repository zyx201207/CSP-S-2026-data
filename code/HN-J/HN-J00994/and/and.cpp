#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,n,a[100000005],maxx=-99999;
signed main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=a[i]&a[j];
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
}
