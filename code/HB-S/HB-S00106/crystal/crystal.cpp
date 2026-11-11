#include <bits/stdc++.h>
using namespace std;
const int MN=5e5+5;
int n,m,a[MN],q[MN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if((n-1)*n/2<=m){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i-1];
	}
	for(int i=n;i>=1;i--){
		if(q[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
