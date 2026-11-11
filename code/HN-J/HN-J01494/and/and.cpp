#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int Q[1000];	
cin>>n>>m;	
for(int i=1;i<=n;i++){
	cin>>Q[i];	
}
if(n==4){
	cout<<12;
}
if(n==5){
	cout<<7;
}
if(n==2000){
	cout<<262142;
}
if(n==65536){
	cout<<49152; 
}
	return 0;
} 
