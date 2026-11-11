#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000006];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=n;i>=m+1;i++){
		ans=a[i]&a[i-1];
	}
	cout<<ans;
	return 0;
}
