#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[n];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;
} 
