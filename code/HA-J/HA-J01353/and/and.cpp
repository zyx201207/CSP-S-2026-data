#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);int ans=a[n-m+1];
	for(int i=n-m+1;i<n;i++){
		ans=(ans || a[i+1]);
	}
	cout<<ans;
	return 0;
}
