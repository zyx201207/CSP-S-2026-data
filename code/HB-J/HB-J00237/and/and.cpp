#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--)
			maxn=max(maxn,a[i]&a[i-m+1]);
	cout<<maxn;
	return 0;
}
