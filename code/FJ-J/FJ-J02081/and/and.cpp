#include<bits/stdc++.h>
using namespace std;
long long n,a[300005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-2];
	return 0;
}
