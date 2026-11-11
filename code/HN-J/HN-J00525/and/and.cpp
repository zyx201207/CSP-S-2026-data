#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[222222]={};
	int x=-999;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	cout<<x;
	return 0;
}
