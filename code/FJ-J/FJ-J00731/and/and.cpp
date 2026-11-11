#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans;
	for(int i=1;i<=m;i++){
		if(i==1) ans=a[n];
		ans=ans&a[n-i+1];
	}
	cout<<ans;
	return 0; 
} 
