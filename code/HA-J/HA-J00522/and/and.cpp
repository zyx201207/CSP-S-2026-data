#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	maxn=a[n];
	for(int i=n-1;i>n-m;i--){
		maxn=maxn&a[i];
	}
	cout<<maxn;
	return 0;
}