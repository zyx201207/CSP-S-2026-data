#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500005],ans=1;
signed main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	for(int i=1;i<=n-ans+1;i++){
		int cnt=0,j=i,o=1;
		for(;j<=n;j++){
			cnt+=(a[j+1]-a[j])*o;
			if(cnt>m)  break;
			o++;
		}
		ans=max(o,ans);
	}
	cout<<ans;
	return 0;
} 
