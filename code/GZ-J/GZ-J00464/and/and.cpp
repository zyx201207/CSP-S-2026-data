//GZ_J00464 遵义市第十九中学 刘宇轩 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(int i=n-m+1;i<=n;i++){
		ans=a[i]&&a[i+1];
	}
	cout<<ans;
	return 0;
}
