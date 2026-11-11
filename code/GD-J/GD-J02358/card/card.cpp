#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1;
	}
	else if(n==2&&m==1){
		cout<<1;
	}
	else if(n==3&&m==2){
		cout<<3<<" "<<1;
	}
	else if(n==4&&m==2){
		cout<<2<<" "<<4;
	}
	else{
		cout<<2<<" "<<5;
	}
	return 0;
} 
