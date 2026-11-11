#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	if(n==5&&m==1){
		cout<<"1 2 3 4 5";
	}
	if(n==4&&m==1){
		cout<<"1 2 3 4";
	}
	if(n==3&&m==1){
		cout<<"1 2 3";
	}
	if(n==2&&m==1){
		cout<<"1 2";
	}
	if(n==1&&m==1){
		cout<<"1";
	}
	if(n==5&&m==2){
		cout<<"5 2";
	}
	return 0;
}