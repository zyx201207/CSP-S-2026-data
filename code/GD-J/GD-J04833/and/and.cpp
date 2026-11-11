#include<bits/stdc++.h> 
using namespace std;
int n,m,ans=0;
int a[200010];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-2;i>=n-m-1;i--){
		
		ans=(ans & a[i]);
	}
	cout<<ans;

	return 0;
}
