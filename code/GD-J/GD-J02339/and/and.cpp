#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","out",stdout);
	int n,m;cin>>n>>m;
	int a[30];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;
}

