#include<bits/stdc++.h>
using namespace std;
long long q[100002],ay[100002];

int awy(int a,int b){
	int a1,b1,i8;
	int c,d;
	c=a1<<2;
	d=b1<<2;
	c=c>>2;
	d=d>>2;
	i8=c&d;

	return i8;
}
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		int qwwq;
		cin>>qwwq;
		q[i]=qwwq;
	}
	for(int i=1;i<=a;i++){
		int qw;
		if(b+i>=a){
			qw=a;
		}else{
			qw=b+i;
		}
		for(int j=i+1;j<=qw;j++){
			q[i]=awy(q[i],q[j]);

		}
		ay[i]=q[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(ay[i]<ay[j]){
				swap(ay[i],ay[j]);
			}
		}
	}
	cout<<ay[1];
	return 0;
}
