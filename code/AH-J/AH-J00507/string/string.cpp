#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],n,k,m1,m2;
char s1[200005];
ll l,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++)cin >> a[i] >> s1[i];
	for(int i = 0;i<n;i++)r+=a[i];
	n--;
	m1 = max(a[n],a[k]);
	m2 = min(a[n],a[k]);
	while(l<=r&&k<n){
		if(m1 == 0){
			m1 = max(a[n],a[k]);
			m2 = min(a[n],a[k]);
		}
		if(m1<m2){
			ll m;
			m = m1;
			m1 = m2;
			m2 = m;
		}
		if(s1[k] != s1[n]){
			ans+=m2;
		}
		if(a[n]>a[k]){
			k++;
		}else if(a[n]<a[k]){
			n--;
		}else{
			k++;
			n--;
		}
		r-=m2;
		l+=m2;
		m1-=m2;
	}
	cout << ans;
	return 0;
}
