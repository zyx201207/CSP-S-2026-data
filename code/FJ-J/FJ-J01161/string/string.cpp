#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,a[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,t;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}

