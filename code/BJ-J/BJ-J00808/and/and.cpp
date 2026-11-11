#include<bits/stdc++.h>
using namespace std;
long long s[200010];
int aa(int a,int b) {
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	sort(s+1,s+1+n,aa);
	for (int i=1;i<=n;i++) {
		if (i==m) {
			cout<<s[i];
			return 0;
		}
	}
	return 0;
}
