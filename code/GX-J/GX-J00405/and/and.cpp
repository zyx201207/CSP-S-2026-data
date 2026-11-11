#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,a[110000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int b=a[n];
	for(int i=n-1;i>=n-m;i--){
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
