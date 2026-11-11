#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans;
	for(int j=1;j<=m-1;j++){
		for(int i=n;i>=1;i--){
			ans=a[i]&a[j];
		}
	}
	cout<<ans;
	return 0;
}
