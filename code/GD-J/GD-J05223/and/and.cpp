#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000100],b;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	b=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		b=b&a[i];
	}
	cout<<b;
	return 0;
}

