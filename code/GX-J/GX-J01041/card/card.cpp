#include <bits/stdc++.h>
using namespace;
int a[1005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==m)cout<<a[i]<<" ";
	else cout<<a[i-1]<<" ";
	return 0;
}
