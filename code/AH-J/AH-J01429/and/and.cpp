#include<bits/stdc++.h>
using namespace std;
int n,a[200001],m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans=(ans & a[i]);
	}cout<<ans;
	
	return 0;
}

