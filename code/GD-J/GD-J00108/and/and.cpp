#include<bits/stdc++.h>
using namespace std;
long long n,m,a[3000],k;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	k=a[n];
	for(int i=2;i<=m;i++){
		k=k&a[n-m+1];
	}
	cout<<k<<endl;
	
	return 0;
} 
