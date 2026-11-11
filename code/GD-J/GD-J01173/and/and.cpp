#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=1;i<m;i++){
		ans=ans&a[n-i];
	}
	cout<<ans;
	return 0;
}
