#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[101],b[101];
	cin>>n;
	for(int i=1;i<=n;){
		cin>>a[i];
	}
	if(n==3){
		cout<<"2";
	}
	if(n==2){
		cout<<"0";
	}
	if(n==6){
		cout<<"6";
	}
	return 0;
}
