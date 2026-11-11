#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[200005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int x=a[1];
	for(int i=2;i<=m;i++){
		x=x&a[i];	
	} 
	cout<<x;
	return 0;
}

