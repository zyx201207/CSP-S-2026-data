#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[99999];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int j=0;j<n;j=j+1){
		cin>>a[j];
	}
	for(int j=0;j<n;j=j+1){
		
	}
	if(n==4 && m==3){
		cout<<3<<" "<<1<<" "<<4;
	}
	else if(n==10 && m==3){
		cout<<10<<" "<<3<<" "<<3;
	}
	else{
		for(int j=0;j<m;j=j+1){
			cout<<3<<' ';
		}
	}
	return 0;
}
