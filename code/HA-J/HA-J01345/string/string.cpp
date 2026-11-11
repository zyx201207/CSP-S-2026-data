#include<bits/stdc++.h>
using namespace std;
char B[10000001];
int c=0;
int cnt=0;
int d;
int main() {
	freopen("string.in","r",stdin);
  	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--) {
		int a;
		char b;
		cin>>a>>b;
		for(int i=c; i<a+c; i++) {
			B[i]=b;
		}
		c+=a;
	}
	d=(int)c/2;
	for(int i=0; i<d; i++) {
		if(B[i]!=B[c-1-i]) {
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

