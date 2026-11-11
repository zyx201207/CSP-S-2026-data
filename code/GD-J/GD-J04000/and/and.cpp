#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200005];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","l",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=0;i<m;i++){
		ans=ans & a[n-i];
	}
	cout<<ans;
	return 0;
}
