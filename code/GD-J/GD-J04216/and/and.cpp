#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[300005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1,j=1;j<=m-1;i--,j++){
		ans=(ans & a[i]);
	}
	cout<<ans;
	return 0;
} 
