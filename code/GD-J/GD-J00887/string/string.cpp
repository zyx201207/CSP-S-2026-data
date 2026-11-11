#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n,a[N], ans;
char c[N];
string st;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) st += c[i];
	}
	int len = st.size();
	for(int i=0, j=len-1;i<=j;i++, j--) {
		if(st[i] != st[j]) ans ++;
	}
	cout<<ans;
	return 0;
}
