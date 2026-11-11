#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,hhy=0;
	cin>>a;
	if(a==1) cout<<0<<endl;
	if(a==2) {
		long long b,d;
		char c,e;
		cin>>b>>c>>d>>e;
		hhy=b+d;
		if(hhy%2==0) {
			if(b!=d)cout<<hhy/2<<endl;
			else cout<<0<<endl;
		}else cout<<(hhy-1)/2<<endl;
	}
	return 0;
}