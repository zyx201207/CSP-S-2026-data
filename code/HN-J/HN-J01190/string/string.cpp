#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long s[n+10];
	char z[n+10];
	long long zh=0;
	for(int i=1; i<=n; i++) {
		cin>>s[i]>>z[i];
		zh+=s[i];
	}
	zh/=2;
	int l=1,r=n;
	while(l<=r) {
		if(z[l]==z[r]) {
			zh-=min(s[l],s[r]);
			if(s[l]==s[r]) {
				l++;
				r--;
			} else if(s[l]>s[r]) {
				s[l]-=s[r];
				r--;
			} else {
				s[r]-=s[l];
				l++;
			}
		} else 	if(s[l]==s[r]) {
				l++;
				r--;
			} else if(s[l]>s[r]) {
				s[l]-=s[r];
				r--;
			} else {
				s[r]-=s[l];
				l++;
			}

		
	}
	cout<<zh;
	return 0;
}
