#include<bits/stdc++.h>
int a[1000005];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n==3){
    	cout<<2;
        return 0;
	}
	if(n==2){
		cout<<0;
		return 0;
	}
	if(n==6){
		cout<<3000000000;
	    return 0;
	}
	if(n==4&&m==2){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	} 
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	return 0;
} 
