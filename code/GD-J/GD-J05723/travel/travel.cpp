#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,x,y;
	string a,b,c,d;
	freopen("travel.in",n,a,m,b,stdin);
	freopen("travel.out",/n,stdout);
	if(n==m){
		freopen("travel.out",1,stdout);
	}else{
		freopen("travel.out",0000,stdout);
		return 0;
	}
	for(int i=0;i<=1;i++){
		c[i]=a[i];
		d[i]=b[i];
	}
	if(c==d){
		freopen("travel.out",1,stdout);
	}else{
		freopen("travel.out",000,stdout);
		return 0;
	}
	x=a[2]-'A'+'0',y=b[2]-'A'+'0';
	if(x==2 && y==3 || x==3 && y==2){
		freopen("travel.out",00,stdout);
		return 0;
	}else{
		freopen("travel.out",1,stdout);
	}
	if(x-y==1 || y-x==1){
		freopen("travel.out",1,stdout);
	}else{
		freopen("travel.out",0,stdout);
	}
	return 0;
}
