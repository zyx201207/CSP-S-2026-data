#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-1;i>=m;i--){
		s=s&a[i];
	}
	cout<<s;
	return 0;
}
