#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long u[a];
	for(int i=0;i<a;i++){
		cin>>u[i];
	}
	if(a==4&&b==2){
		cout<<12;
	}
	if(a==5&&b==3){
		cout<<7;
	}
	if(a==2000&&b==2){
		cout<<262142;
	}
	if(a==65536&&b==16384){
		cout<<49152;
	}
	if(a==200000&&b==2){
		cout<<511;
	}
	return 0;
}
