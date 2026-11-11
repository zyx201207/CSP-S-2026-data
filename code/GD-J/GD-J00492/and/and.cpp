#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int am=-1,xb;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		am=max(am,a[i]);
	}
	sort(a+1,a+n+1); 
	int ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		//cout<<a[i]<<" ";
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

