#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,c=0,q;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a,a+1+n);
	
	for(int i=1;i>-1;i++){
		c=c+a[i];
		if(c>=m) {
			q=i;
			i=-99;
		}
	}
	cout<<q;
	
	return 0;
}
