#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
ll n,m,ans=1;
ll a[N];
int main() {
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int fl=1;
	for(int i=1; i<=n; i++)cin>>a[i];
	ll w=a[2]-a[1];
	for(int i=1;i<=n;i++)if(a[i]-a[i-1]!=w)fl=0;
	sort(a+1,a+1+n);
	if(fl) {
		//cout<<"&&&";
		ll cnt=0;
		for(int i=n; i>=1; i--) {
			if(a[n]-a[i]<=m) {
				cnt++;
				m-=(a[n]-a[i]);
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=2; i<=n; i++) {
		int q[N];
		for(int j=1; j<=i; j++) {
			q[j]=a[i]-a[j];
			//cout<<"&&&";
		}
		ll cnt=0;
		ll w=m;
		sort(q+1,q+1+i);
		for(int j=1; j<=i; j++) {
			if(w>=q[j]) {
				w-=q[j];
				cnt++;
			} else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
