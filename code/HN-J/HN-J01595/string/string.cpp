#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long sum,a=1,b;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		int q;
		char p;
		cin>>q>>p;
		for(int j=1; j<=q; j++) {
			s[a]=p;
			a++;
		}
		b+=q;
	}
	a--;
	for(int i=1; i<=b/2; i++) {
		if(s[i]!=s[a-i+1]) {
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
