#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200005],sum[200005],mx;
char c[200005];
ll cnt1,cnt2,ans;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		mx=max(mx,a[i]);
	}
	if((n<=2000) || mx<=500) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=a[i]; j++)s+=c[i];
		}
		int l=s.size();
		s=" "+s;
		for(int i=1; i<=(l+1)/2; i++) {
			if(s[i]!=s[l-i+1])ans++;
		}
		cout<<ans;
		return 0;
	}
	int i=1,j=n;
	while(i<j-1) {
		if(a[i]==a[j]) {
			if(c[i]!=c[j])ans+=a[i];
			i++,j--;
		} else if(a[i]>a[j]) {
			ll tmp=a[i];
			while(tmp-a[j]>=0 && i<j) {
				tmp-=a[j];
				if(c[i]!=c[j])ans+=a[j];
				j--;
//				cout<<1;
			}
			if(tmp>=0) {
				j--;
				if(c[i]!=c[j])ans+=tmp;
				a[j]-=tmp;
			}
		} else {
			ll tmp=a[j];
			while(tmp-a[i]>=0 && i<j) {
				tmp-=a[i];
				if(c[i]!=c[j])ans+=a[i];
				i++;
//				cout<<1;
			}
			if(tmp>=0) {
				i++;
				if(c[i]!=c[j])ans+=tmp;
				a[i]-=tmp;
			}
		}
	}
	if(i==j) {
		if(a[i]%2==1)ans++;
	}
	cout<<ans;
	return 0;
}
