#include<bits/stdc++.h>
#include<iostream>
#include<string>
#define asd long long
using namespace std;
asd a1,a2,a3,a4,a5,f,cnt=0,ans,n;
int a[1005];
struct node {
	asd a,b;
	string s;
	double p;
};
node miding(asd& x,asd& y){
	int m;
	for(int i=1;i<=m;i++){
		if(i%a1==i%a2==i%a3==i%a4==i%a5){
			a[i-(i+2)*n+1]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a1>>a2>>n;
	if(a1==a2&&a2==a3&&a3==a4&&a4==a5)cout<<a1*a2*a3*a4*a5;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt++;
	}
	cin>>a3>>a4>>f>>a5;
	if(f>a1+a2+a4+a5){
		f-=miding(a3,a4);
	}
	asd id=1;
	while(id<a1*a5){
		for(int i=1;i<=id;i++){
			id/=2;
			id+=id+id/2+id/4;
		}
		if(id%7==0)cout<<(((a1+a2+a3+a4+a5)*f/id/4)+a1*a2*a3*a4*a5-miding(n+miding(f,n),a1+a2+a3+a4+a5));
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
	
	
	
	
}
