#include<bits/stdc++.h>
using namespace std;
int a[10000]={0};
int main(){	
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int m=0,n=0;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(i>=1&&a[i]==a[i-1]){
		a[i]=0;
		a[i-1]=0;
	}
}
for(int i=n;i>=0;i--){

cout<<a[i]<<endl;}
return 0;
}
