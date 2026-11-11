#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[10001],n,s;
	cin >>n>>s;
	for (int i=1;i<=n;++i){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-s+1];
	return 0;
}
