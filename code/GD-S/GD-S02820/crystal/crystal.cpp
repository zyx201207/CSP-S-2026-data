#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],l=1,tot,ans,now;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		tot+=(i-1-l+1)*(a[i]-a[i-1]);
		while (tot>m){
			tot-=a[i]-a[l];l++;now--;
		}now+=1;ans=max(now,ans);
	}cout<<ans<<endl;
	return 0;
}
