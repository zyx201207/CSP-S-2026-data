#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]={0};
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	cin>>a[1];
	int ans=a[1];
	
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
	}
	if(n==m){
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	
	return 0;
}
