#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[2];
	cout<<a[2]-a[1];
	cout<<a[1];
	return 0;
}
