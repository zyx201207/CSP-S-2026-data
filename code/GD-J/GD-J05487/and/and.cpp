#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ma=0;
	for(int i=0;i<n;i++)cin>>a[n];
	for(int i=m;i<n;i++){
		for(int j=1;j<=m;j++){
			ma=max(ma,a[i-j]&a[i-j+1]);
		}
	}
	cout<<ma;
	return 0;
}
