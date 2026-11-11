#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int a[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=floor(1.0*m/abs(a[1]-a[2])+1);
	if(ans<1) ans=1;
	if(ans>n) ans=n;
	cout<<ans;
	return 0;
}
/*

*/
