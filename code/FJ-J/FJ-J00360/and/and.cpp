#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={};
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b,c;
	for (int i=1;i<=n;i++){
		
		if(a[i]>=a[i+1]) b=a[i];
		else b=a[i+1];
	}
	cout<<b;
	return 0;
}
