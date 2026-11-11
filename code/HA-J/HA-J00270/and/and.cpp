#include <bits/stdc++.h>
using namespace std;
int a[10000003];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn = 0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	cout<<a[n/2+1];
	return 0;
}