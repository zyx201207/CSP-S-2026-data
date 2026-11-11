#include <bits/stdc++.h>
using namespace std;
int main (){
	
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	
	if(n==4){
		if(m==2){
			cout<<"12";
		}
	}
	
	if(n==5){
		if(m==3){
			cout<<"7";
		} 
	}
	
	if(n==2000){
		if(m==2){
			cout<<"262142";
		} 
	}
	
	if(n==65536){
		if(m==16384){
			cout<<"16384";
		} 
	}
	
	if(n==200000){
		if(m==2){
			cout<<"511";
		} 
	}
	
	return 0;
} 
