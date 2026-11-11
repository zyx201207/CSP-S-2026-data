#include <bits/stdc++.h>
using namespace std;

long long n,ans,r;
string x;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",n);
	for(int i = 0;i < n;i++){
		long long a;
		char b;
		scanf("%lld,%c",&a,&b);
		for(int j = 0;j < a;j++) x = x + b;
	}
	r = x.size()-1;
	for(long long l = 0;l < x.size()/2;l++){
		if(x[l] != x[r]) ans++;
		r--;
	}	
	printf("%lld",&ans);
	return 0;
}
