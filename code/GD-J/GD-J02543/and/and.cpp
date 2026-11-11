#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>n-m;i--){
		//cout<<a[i]<<" ";
		ans&=a[i]; 
	}
	
	cout<<ans;
	return 0;
} 
