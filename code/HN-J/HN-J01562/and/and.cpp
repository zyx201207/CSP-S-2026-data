#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],num = INT_MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>n-m;--i){
		num = num & a[i];
	}
	cout<<num;
	return 0;
}
