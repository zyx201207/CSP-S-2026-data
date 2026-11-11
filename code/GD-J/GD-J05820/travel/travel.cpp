#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int sum=0;
	for(int i=0;i<2;i++){
	   if(a[i]==c[i]){
	   	sum++;
	   }
	}
	if(sum==2){
	 cout<<1;
	}else{
	 cout<<0;
	}
	sum=0;
	for(int i=0;i<2;i++){
	   if(b[i]==d[i]){
	   	cout<<1;
	   }else{
	   	cout<<0;
	   }
	}
	if(b[2]==d[2] || b[2]==d[2]-1|| b[2]==d[2]+1){
	  cout<<1;
	}else{
	  cout<<0;
	}
	return 0;
}
