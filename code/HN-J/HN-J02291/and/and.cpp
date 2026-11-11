#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005]; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,q=0,q1=0;
	if(n==m){
		for(int i=1;i<=n;i++){
			ans+=(a[i]&a[i+1]);
		}
		cout<<ans<<endl; 
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i-=2){
		ans+=(a[i]&a[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

