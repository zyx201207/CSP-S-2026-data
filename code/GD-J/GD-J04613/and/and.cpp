#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxi(-1);
	cin>>n>>m;
	int a[n+1];
	for(int i(0);i<n;i++)cin>>a[i];
	for(int i(0);i<n;i++)
		for(int j(i+1);j<n;j++)
			maxi=max((a[i]&a[j]),maxi);
	cout<<maxi;
	return 0;
} 
