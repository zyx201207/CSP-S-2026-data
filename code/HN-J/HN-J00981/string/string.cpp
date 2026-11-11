#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string r;
	for(int i=0; i<n; i++) {
		long long a;
		char c;
		cin>>a>>c;
		for(int j=0; j<a; j++) {
			r+=c;
		}
	}
	long long sum=0;
	for(int i=0; i<r.size()/2; i++) {
		if(r[i]!=r[r.size()-1-i]) {
			sum++;
		}

	}
	cout<<sum;
	return 0;
}

