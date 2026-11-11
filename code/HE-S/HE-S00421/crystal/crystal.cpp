#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL n,m;
LL a[N],c[N],sum[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	LL he=0,ans=0;
	for(int l=1,r=1;r<=n;r++){
		c[r]=a[r]-a[r-1];
		sum[r]=sum[r-1]+c[r];
		he+=(c[r]*(r-l));
		while(he>m&&l<=r){
			he-=(sum[r]-sum[l++]);
		}
		ans=max(ans,(LL)r-l+1ll);
	}
	cout<<ans;
	return 0;
}
