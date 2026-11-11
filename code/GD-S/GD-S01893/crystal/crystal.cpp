#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],cnt,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(r<n){
		r++;
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m) cnt-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
