#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;
const int N = 200005;
struct str {
	int len;
	char ch;
};
int n;
ll m;
int mid,tot;
int a[N];
char c[N];
ll ans;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=a[i]; j++)
			s+=c[i];
	for (int i=0,j=m-1; i+1<=m/2; i++,j--)
		if (s[i]!=s[j])
			ans++;
	cout<<ans;
	return 0;
}
