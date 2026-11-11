#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000];
int sb(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,sb);
	n=a[1];
	for(int i=2;i<=m;i++){
		n=n&a[i];
	} 
	cout<<n;
	return 0;
}
