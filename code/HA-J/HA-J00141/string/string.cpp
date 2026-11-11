#include <bits/stdc++.h>
using namespace std;
long long a,b[300000],n=1,d=0,cnt=0;
char c[200000],s[300000000000000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++) {
		cin>>b[i]>>c[i];
		d+=b[i];
	}
	for(int i=1;i<=a;i++) {
		for(int j=1;j<=b[i];j++) {
			s[n]=c[i];
			n++;
		}
	}
	for(int i=1;i<=d/2;i++) {
		if(s[i]!=s[d-i+1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
