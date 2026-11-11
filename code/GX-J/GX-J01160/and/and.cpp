#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	c=a[n-1];
	for(int i=n-2;i>n-1-m;i--){
		c=c&a[i];
	}
	cout<<c;
	return 0;
}


