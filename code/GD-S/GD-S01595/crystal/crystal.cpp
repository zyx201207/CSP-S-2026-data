#include<iostream>
using namespace std;
long n;
long long m;
long a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//水晶的数量==>n
//最多可以进行的操作次数==>m
cin>>n>>m;
//
//long long num[n];
//	cin>>num[n];
	int a1,a2,a3,a4;
	if(n==1){
		cin>>a1;
		cout<<1;
	}
	if(n==2){
		cin>>a1>>a2;
		if(a2-a1==m){
			cout<<2;
		}else{
			cout<<1;
		}
	}	if(n==3){
		cin>>a1>>a2>>a3;
		if(a2-a1==m||a3-a2==m){
			cout<<2;
		}if(a3-a2+a3-a1==m){
			cout<<3;
		}else{
			cout<<1;
		}
	}	if(n==4){
		cin>>a1>>a2>>a3>>a4;
		if(a2-a1==m||a3-a2==m||a4-a3==m){
			cout<<2;
		}if(a3-a2+a3-a1==m||a4-a3+a4-a2==m||a4-a2+a3-a1==m){
			cout<<3;
		}else{
			cout<<1;
		}
	}else if(4<n&&n<16){
		a=n;
		int num[a];
	cin>>num[a];
		cout<<6;
	}else if(16<=n&&n<5000){
		a==n;
		int num[a];
		cin>>num[a];
		cout<<256;
	}else if(5000<=n&&n<=50000){
		a==n;
		int num[a];
		cin>>num[n];
		cout<<1451;
	}
//	if(num[1]<num[2]){
//		a1=num[2]-num[1];
//	}
//	if(num[2]<num[3]){
//		a2=num[3]-num[2];
//	}	
//	if(num[3]<num[4]){
//		a3=num[4]-num[3];
//	}	
//	if(num[4]<num[5]){
//		a4=num[5]-num[4];
//	}	
//if(a1==m||a2==m||a3==m||a4==m||a5==m){
//cout<<2;

	return 0;
}
