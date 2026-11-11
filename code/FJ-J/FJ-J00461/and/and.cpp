#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[21000];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a[1],a[n]);
	int b=a[1];
	for(long long i=2;i<=m;i++){
		b=b&&a[i];
	}
	cout<<b;
	return 0;
}
