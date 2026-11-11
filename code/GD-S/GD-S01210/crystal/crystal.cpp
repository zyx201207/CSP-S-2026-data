#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int j=1,ans=0;
	for(int i=2;i<=n;i++){
		while(j<i && s[i-1]-s[j-1]+m<a[i]*(i-j)) j++;
		ans=max(ans,(i-j+1));
	}
	cout<<ans;
	return 0;
}
