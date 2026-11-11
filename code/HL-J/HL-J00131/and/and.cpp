#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[m];
	for(int i=1;i<=n;i++){
		cin>>a[m];
	}
	sort(a,a+n);
	cout<<a[m];
	return 0;
}
