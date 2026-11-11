#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,mm,a[500005],maxn=1;
	cin>>n>>mm;
	ll m=mm,l=1;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		if (l==i) continue;
		m=m-(a[i]-a[i-1])*(i-l);
		while (m<0){
			m=m+a[i]-a[l];
			l++;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}
