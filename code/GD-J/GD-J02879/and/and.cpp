#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[100086];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long tool=a[n];
	
	for(int i=n-1;i>n-m;i--){
		tool=tool&a[i];
	}
	cout<<tool;
	
	return 0;
}
