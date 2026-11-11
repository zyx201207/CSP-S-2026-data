#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
long long ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c;
		while(a[i]--) s+=c;
	}
	for (int i=0;i<s.size()/2;i++)
		if (s[i]!=s[s.size()-i-1]) ans++;
	cout << ans;
	return 0;
}

