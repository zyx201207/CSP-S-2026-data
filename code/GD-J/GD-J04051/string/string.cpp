#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[200010],r[200010],n,ans;string s;
char c[200010];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;int sum=0;char c;
	for(int i=1,x;i<=n;i++) {
		cin>>x>>c;sum+=x;
		for(int i=1;i<=x;i++) s+=c;
	}
	for(int i=0;i<sum/2;i++) if(s[i]!=s[sum-i-1]) ans++;
	cout<<ans;
}
