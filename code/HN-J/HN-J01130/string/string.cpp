#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long b=0,n;
	cin>>n;
	long long a[n];
	char c[n];
	for(int i=0; i<n; i++) {
		cin>>a[i]>>c[i];
	}
	if(n==1) {
		cout<<0;
		return 0;
	}
	if(n==2) {
		if(c[0]==c[1]) {
			cout<<0;
			return 0;
		}
		if(a[0]<=a[1]) {
			cout<<a[0];
			return 0;
		}
		cout<<a[1];
		return 0;
	}




	fclose(stdin);
	fclose(stdout);
	return 0;
}
