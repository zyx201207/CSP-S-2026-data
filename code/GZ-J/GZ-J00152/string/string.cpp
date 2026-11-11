//GZ-J00152  遵义市第四中学 曾皓宇
#include <bits/stdc++.h>
using namespace std;

long long n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;string s;
	long long z=0;
	for(int i=1; i<=n; i++) {
		long long c;
		char a;
		cin>>c>>a;
		for(int k=1; k<=c; k++) {
			s[z]=a;
			z++;
		}
	}
	long long j=(z-1)/2,h=0;
	for(int i=0; i<=j; i++) {
		if(s[i]!=s[z-1-i]){
			h++;
		}
	}
	cout<<h;
	return 0;
}
