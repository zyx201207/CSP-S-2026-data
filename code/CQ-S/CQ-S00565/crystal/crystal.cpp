#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],pre[500005],Mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m; for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1); for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1; 
		} Mx=max(Mx,i-ans+1ll);
	} cout << Mx; return 0;
}
