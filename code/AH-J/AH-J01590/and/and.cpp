#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		vis[i] = 1;
	}
	for(int i = 29;i>=0;i--){
		int num;
		num = 0;
		for(int j = 1;j<=n;j++){
			num = num+(vis[j] && a[j]&(1<<i));
		}
		if(num<m){
			continue;
		}
		ans = ans+(1<<i);
		for(int j = 1;j<=n;j++){
			if(vis[j] && (a[j]&(1<<i)) == 0){
				vis[j] = 0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

