#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],mx,sum;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;a[0]=a[1];
	while(r<=n){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l<r)sum-=abs(a[l]-a[r]),l++;
		//cout<<l<<' '<<r<<':'<<sum<<'\n';
		if(sum<=m)mx=max(mx,r-l+1);
		r++;
	}cout<<mx;
	return 0;
}
