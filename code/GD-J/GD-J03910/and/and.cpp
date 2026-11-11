#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
