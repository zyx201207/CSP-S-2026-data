#include <bits/stdc++.h>
#define ll long long
#define inf 0x3fffffff
using namespace std;
ll n,m,a[500005],ans=1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	ll l=1,r=1,flag=0;
	while(l<=r&&r<n){
		if(!flag) r++;
		sum=(a[r]-a[r-1])*(r-l);
		if(m<sum){
			l++;
			m+=a[r-1]-a[l-1];
			flag=1;
		} else {
			m-=sum;
			ans=max(ans,r-l+1);
			flag=0;
		}
	}
	cout << ans;
	return 0;
}
