#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,m,a[MAXN];
long long maxx(long long a,long long b){
	if (a>=b) return a;
	return b;
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		long long ans=LLONG_MIN;
		for (int i=1;i<=n;i++) ans=maxx(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if (m==2){
		long long ans=LLONG_MIN;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans=maxx(ans,long(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if (m==n){
		long long ans=a[1];
		for (int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else {
		sort(a+1,a+1+n,greater<int>());
		cout<<a[m];
		return 0;
	}
	return 0;
}
