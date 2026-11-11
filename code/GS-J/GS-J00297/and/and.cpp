#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[n-1]==1){
		cout<<"1";
	}else if(m==1){
		cout<<a[n-1];
	}else if(m==2){
		cout<<a[n-2];
	}else if(m==n){
		cout<<"0";
	}else if(m==n-1){
		cout<<a[1];
	}else{
		cout<<a[n-m];
	}
	return 0;
}
