#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5;i++){
		cin>>a[i];
	}
	for(int i=1;i<=5;i++){
		cin>>b[i];
	}
	int f1=1,f2=1,f3=1,f4=1;
	for(int i=1;i<=2;i++){
		if(a[i]!=b[i]){
			f1=0;
		}
	}
	for(int i=3;i<=4;i++){
		if(a[i]!=b[i]){
			f2=0;
		}
	}
	if(!(a[5]=='F'&&b[5]=='D'||a[5]=='D'&&b[5]=='F'||a[5]=='C'&&b[5]=='A'||a[5]=='C'&&b[5]=='B'||a[5]=='B'&&b[5]=='C'||a[5]=='B'&&b[5]=='A'||a[5]=='A'&&b[5]=='B'||a[5]=='A'&&b[5]=='C')){
		f3=0;
		f4=0;
	}
	else{
		if(a[5]=='C'&&b[5]=='A'||a[5]=='A'&&b[5]=='C'){
			f4=0;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
