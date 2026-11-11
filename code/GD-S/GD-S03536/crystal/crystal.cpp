#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m;
long long a[MAXN],b[MAXN],sum[MAXN],sum1[MAXN],ans,l,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		sum1[i]=b[i]*(i-1)+sum1[i-1];
	}
	while(r!=n){
		if(sum1[r]-sum1[l]-(a[r]-a[l])*(l-1)>m)l++;
		else r++;
		ans=max(ans,r-l+1);
	}
	cout << ans-1;
}
