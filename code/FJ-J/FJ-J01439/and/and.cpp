#include<bits/stdc++.h> 
using namespace std;
int n,m,ans;
long long a[200011];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
