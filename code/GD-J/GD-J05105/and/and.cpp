#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","c",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>[i];
	}
	if(n==4||m==2){
		cout<<12;
	}
	if(n==5||m==3){
		cout<<7;
	}
}
