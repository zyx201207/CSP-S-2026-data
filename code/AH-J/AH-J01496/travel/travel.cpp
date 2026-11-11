#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a1,b1,a2,b2,x=0;
	char a3,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if(a1==b1){
		cout<<1;
	}else{
		x=1;
		cout<<0;
	}
	if(a2==b2&&x==0){
		cout<<1;
	}else{
		x=1;
		cout<<0;
	}long long i;
	if(a3<='C'&&b3<='C'&&x==0){
		i=1;
		if(a3>='D'&&b3>='D'){
			i=2;
		}
		cout<<1;
	}else{
		x=1;
		cout<<0;
	}
	if((a3-b3==i||b3-a3==i)&&x==0){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
