#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m+1;i--){
		ans=min(ans,a[i]);
	}
	cout<<ans;
	return 0;
} 
