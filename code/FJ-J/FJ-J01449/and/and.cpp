#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(check()){
		ans=a[n-1];
		for(int i=n-1;i>=(n-2*m+1);i-=2){
			ans=(ans&a[i]);
		}
	}
	else{
		ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans=(ans&a[i]);
		}
	}
	cout<<ans;
	return 0;
}

