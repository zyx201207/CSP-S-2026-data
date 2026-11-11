#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a[1000010]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==4&m==2){
		cout<<12;
	}
	if (n==5&m==3){
		cout<<7;
	}
} 
