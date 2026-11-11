#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],ans,m;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n-m+1];
	while(m--){
		  if(m>=1){
		  	 ans&=a[n-m+1];
		  }
	}
	cout<<ans;
	return 0;
}
