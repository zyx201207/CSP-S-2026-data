#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[20010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-m];
}
