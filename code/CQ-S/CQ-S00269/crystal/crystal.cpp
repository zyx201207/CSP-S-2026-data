#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,ans=1,a[500005];
double sum;

int main() {
	freopen("crystal .in","r",stdin);
	freopen("crystal .out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for(ll i=1;i<=n;i++) {
		cin >>a[i];
		sum+=(double)a[i];
	}
	sum/=n;
	sort(a+1,a+n+1);
	ll cnt=lower_bound(a+1,a+n+1,sum)-a-1,b;
	if(sum-(double)a[cnt-1]<=(double)a[cnt]-sum) b=a[cnt-1];
	else b=a[cnt];
	ll i=cnt-1,j=cnt+1;
	for(;;) {
		if(i>=1&&j<=n) {
			if(a[cnt]-a[i]<=a[j]-a[cnt]) {
				m-=a[cnt]-a[i];
				if(m<0) break;
				ans++;
				i--;
			}
			else {
				m-=a[j]-a[cnt];
				if(m<0) break;
				ans++;
				j++;
			}
		}
		else if(i<1&&j>n) break;
		else if(i<1) {
			m-=a[j]-a[cnt];
				if(m<0) break;
				ans++;
				j++;
		}
		else {
			m-=a[cnt]-a[i];
				if(m<0) break;
				ans++;
				i--;
		}
	}
	cout <<ans;
	return 0;
}
