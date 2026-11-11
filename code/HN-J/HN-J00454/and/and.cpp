#include <bits/stdc++.h>
using namespace std;
int n,m,a[100086],ant,b[100086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);/*
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}//*/
	ant=a[n];
	for(int i=n,j=1;i>n-m,j<=m;i--,j++){
		//cout<<a[i]<<" ";
		b[j]=a[i];
	}//*
	for(int i=1;i<=m-1;i++){
		b[i+1]=b[i+1]&b[i];
	}//*/
	cout<<b[m];
	//cout<<a[n-m];
	return 0;
}
