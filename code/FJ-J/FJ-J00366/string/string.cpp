#include<bits/stdc++.h>
using namespace std;
char str[999999999];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int s;
		char ch;
		cin>>s>>ch;
		for(int i=1; i<=s; i++) {
			m++;
			str[m]=ch;
		}
	}
	for(int i=1; i<=m/2; i++) {
		if(str[i]!=str[m]) {
			ans=ans+1;
		}
		m--;
	}
	cout<<ans;
	return 0;
}
