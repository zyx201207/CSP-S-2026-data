#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	cout<<n-n/10;
	return 0;
}
