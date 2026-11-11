#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
#define int long long
int n,m,a[maxn];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,x=m,ans=-1;
	for(int r=2;r<=n;r++){
		x-=(r-l)*(a[r]-a[r-1]);
		while(x<0){
			l++;
			x+=a[r]-a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
