#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r"stdin);
	freopen("crystal.out","w"stdout);
	int a[10000];
	int n,m,b,c;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"1";
		return 0;
	}
	if(a[0]>=a[1]){
		b=a[0]-a[1];
	}else{
		b=a[1]-a[0];
	}
	if(n==2&&b<=m){
		cout<<"2";
		return 0;
	}
	if(n==2&&b>m) {
		cout<<"1";
		return 0;
	}
	if(n==3){
		if(b>=m){
			cout<<"2";
			return 0;
		}
	}
	cout<<"3";
	return 0;
}
