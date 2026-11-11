#include<bits/stdc++.h>
using namespace std;
long long a,b[200005],k=0,op=0,e=0,ans;
string c[2000005],z;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1; i<=a; i++) {
		cin>>b[i]>>c[i];
		e+=b[i];
		for(int j=1; j<=b[i]; j++) {
			z+=c[i];
		}
	}
	for(int i=z.size()-1; i>=0; i--) {
		if(z[k]==z[i]) {
			op++;
		}
		k++;
	}
	if(op==z.size()) {
		cout<<0;
	} 
	else {
		if(op+z.size()-2*op>0) {
			ans+=(e+op)/2;
			cout<<ans-op;
		}
	}

	return 0;
}
