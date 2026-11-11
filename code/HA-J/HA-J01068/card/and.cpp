#include<bits/stdc++.h>
using namespace std;
long long b=0;
int a[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b=a[n];
	for(int i=n;i>n-m;i--){
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
