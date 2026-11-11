#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=n-1;i>n-m;i--){
		a[i]=a[i+1]&a[i];
	}
	cout<<a[n-m+1];
	return 0;
}
