#include<bits/stdc++.h>
using namespace std; 
int a[222222];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mk=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else{
		sort(a+1,a+n+1);
		cout<<a[n/2+1];
	}
	return 0;
}
