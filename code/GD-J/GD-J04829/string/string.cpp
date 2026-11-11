#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char s[N];
string str;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
		for(int j=1; j<=a[i]; j++) str+=s[i];
	}
	int len=str.size();
	for(int i=0;i<len;i++) {
		if(i>=len-i-1) break;
		if(str[i]!=str[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
