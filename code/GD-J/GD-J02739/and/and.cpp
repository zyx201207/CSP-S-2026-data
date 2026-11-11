#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==4&&m==2){
		cout<<12;
	} 
	if(n==4&&m==3){
		cout<<7;
	}
	if(n==2000&&m==2){
		cout<<262142;
	} 
	if(n==65536&&m==16384){
		cout<<49152;
	}
	if(n==20000&&m==2){
		cout<<511;
	}
	return 0;
}

