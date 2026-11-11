#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,dp[N],vis[N];
char a[N];
//marks coming!!
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ans=-1,t=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;i++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout << ans << endl;
    return 0;
}
