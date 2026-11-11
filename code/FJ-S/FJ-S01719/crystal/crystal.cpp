#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,sum=0;
	for(int r=1,l=1;r<=n;r++){
		sum+=a[r];
		while(l<=r&&(r-l+1)*a[r]-sum>m)sum-=a[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
