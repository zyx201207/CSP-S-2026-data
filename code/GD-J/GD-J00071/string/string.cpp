#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int n,a[MAXN];
long long l[MAXN],r[MAXN];
char c[MAXN];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s="";
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		r[i]=r[i-1]+a[i];
		l[i]=r[i-1]+1;
		for(int j=1; j<=a[i]; j++) {
			s+=c[i];
		}
	}
	int l=s.length();
	long long ss=0;
	for(int i=0; i<l/2; i++) {
		if(s[i]!=s[l-i-1]) {
			ss++;
		}
	}
	cout<<ss;
	return 0;
}
