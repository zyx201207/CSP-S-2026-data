#include<bits/stdc++.h>
using namespace std;
int a[200005]={0},n,m,s=0;
int main(){
freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];  
	}
	sort(a,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
