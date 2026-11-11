#include<bits/stdc++.h>
#define int long long
using namespace std;
void dfs(int k){
	
}
int n,m,a[200005],ans=-1e9,cnt;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		for(int j=i;j<=i+m-1;j++){
			cnt=(a[i] & a[i+1]);
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
