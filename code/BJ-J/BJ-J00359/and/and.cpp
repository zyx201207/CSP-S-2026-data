#include <bits/stdc++.h>
using namespace std;
long long a[100100],c[100100],b[100100];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-1];
	return 0;
}
	

