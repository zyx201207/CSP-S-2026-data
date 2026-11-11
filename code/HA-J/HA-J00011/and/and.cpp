#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	int c,d,e;
	int b[n+1];
	for (int i=0;i<=n;i++){
		c=max(a[i],a[i+1]);
		b[i]=c;
	}
	
	
	int n2 = n/2;
	int n1 = n%2+n2;
	int n3 = max(n1,n2);
	cout << b[n3];
	
	return 0;	
}
