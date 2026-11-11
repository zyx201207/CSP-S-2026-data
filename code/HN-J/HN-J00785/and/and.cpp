#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200001],b[200001],i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	ans=a[n];
	for(i=1;i<m;i++) ans=ans and a[n-i]; 
	cout<<ans;
	return 0;
}
