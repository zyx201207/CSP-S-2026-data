#include<bits/stdc++.h>
using namespace std;
int a[50005],b[50005],n,s=0;
int d(int i,int m,int j){
	if(m>=b[i]*j&&i<n){
		return d(i+1,m-b[i]*j,j+1)+1;
	}else{
		return 0;
	}
	return 1;
}
int main(){
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		s=max(d(i,m,1),s);
	}
	cout<<s;
}
