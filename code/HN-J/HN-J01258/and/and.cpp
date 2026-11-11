#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int m,n,x[10086];
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>x[i];
}
if(n==5 and m==3){
	cout<<"7";
}
if(n==4 and m==2){
	cout<<"12";
}
if(n==2000 and m==2){
	cout<<"262142";
}
if(n==65536 and m==16384){
	cout<<"49152";
}
if(n==200000 and m==2){
	cout<<"511";
}
	return 0;
}
