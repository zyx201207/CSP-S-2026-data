#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ans,now,cnt[40];
string s[200010];
bool cmp(string a,string b) {
	return a>b;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=29; j++)s[i]+="0";
		for (int j=0; j<=29; j++) {
			s[i][29-j]=((a[i]>>j)&1)+'0';
		}
	}
	for (int i=0; i<=29; i++) {
		for (int j=1; j<=n; j++) {
			if (s[j][i]=='1')cnt[i]++;
		}
		if (cnt[i]<m) {
			for (int j=1; j<=n; j++) {
				s[j][i]='0';
			}
		}
	}
	now=n;
	for (int i=0; i<=29; i++) {
		if (cnt[i]<m){
			ans=ans*2;
			continue;
		}
		sort(s+1,s+1+now,cmp);
		int cntt=now;
		for (int j=1; j<=now; j++) {
			if (s[j][i]=='0') {
				cntt=j-1;
				break;
			}
		}
		if (cntt<m) {
			for (int j=1; j<=now; j++) {
				s[j][i]='0';
			}
			ans=ans*2;
		} else {
			for (int j=1; j<=now; j++) {
				s[j][i]='0';
			}
			ans=ans*2+1;
			now=cntt;
		}
	}
	cout<<ans;
	return 0;
}
