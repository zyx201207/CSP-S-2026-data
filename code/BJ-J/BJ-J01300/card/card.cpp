#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<m<<a[3]<<n;
	return 0;
}