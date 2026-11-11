#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,l;
char c[200005];
signed main() {//±©Á¦Ä£Äâ£¬O(sum(a[i])*n)×óÓÒ
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i]>>c[i],l+=a[i];
	string s=" ";
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) s+=c[i];
	}
	for(int i=1; i<=l/2; i++) {
		if(s[i]!=s[l-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
