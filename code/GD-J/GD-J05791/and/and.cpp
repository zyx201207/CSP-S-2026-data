#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopem("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;
}
