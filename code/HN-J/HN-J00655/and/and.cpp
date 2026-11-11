#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++)ans=max(ans,(a[i]&a[j]));
	}
	int b=a[1];
	for(int i=2;i<=n;i++)b=(b&a[i]);
	cout<<max(b,ans);
	return 0;
}
