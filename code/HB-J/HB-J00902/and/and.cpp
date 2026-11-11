#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1145141],dp,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp=a[i];
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				dp=max(dp|a[k],dp);
			}
		}
		ans=max(ans,dp);
	}
	cout<<ans;
	return 0;
}
