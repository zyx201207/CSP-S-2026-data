#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	int n,m;
	int a[N];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[m-1];
	return 0;
}
