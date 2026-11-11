#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define debug(x) freopen(x".in","r",stdin);freopen("debug.txt","w",stdout);
using namespace std;
typedef long long ll;
ll n,m,a[200010],ans;
int main() {
	debug("and4");
	cin>>n>>m;
	for(int i=0; i<n; i++)cin>>a[i];
	if(n<=20&&m<=n) {
		sort(a,a+n);
		ans=a[n-1];
		for(int i=n-1-1; i>=n-m; i--)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=2000) {
		if(m==1) {
			long long mx=-1;
			for(int i=0; i<n; i++) {
				mx=max(a[i],mx);
			}
			cout<<mx;
		} else if(m==2) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(i!=j) {
						ans=max(ans,(a[i]&a[j]));
					}
				}
			}
			cout<<ans;
		} else if(m==n) {
			ans=a[0];
			for(int i=1; i<n; i++)ans&=a[i];
			cout<<ans;
		}
		return 0;
	}
	if(m==n-1) {
		bool flag=true;
		long long mx=a[1];
		ans=a[0];
		for(int i=1; i<n; i++) {
			if((a[i]&ans)==0) {
				if(flag==true) {
					flag=false;
					continue;
				} else {
					ans=0;
				}
			}
			ans&=a[i];
		}
		for(int i=2; i<n; i++) {
			mx&=a[i];
		}
		cout<<max(mx,ans);
		return 0;
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-1-1; i>=n-m; i--)if((ans&a[i])!=0)ans&=a[i];else m++;
	cout<<ans;
	return 0;
}

