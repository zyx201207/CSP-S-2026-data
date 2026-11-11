#include<bits/stdc++.h>
using namespace std;
int a,c;
int s,s2,z,z2;
int d,b1,b2,b3;
bool a1,c1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	cin>>a>>a1>>c>>c1;
	if(a==c&&a!=1&&a!=16){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a1==c1){
		cout<<0<<0<<0;
		return 0;
	}
		s=a1/10;
		z=a1%10;
		s2=c1/10;
		z2=c1%10;
		if(s==s2&&z==z2){
			b1=1;
		}
		if(c1-a1||a1-c1==1){
		b3=1;
	}
		if(a1+1==c1||c1+1==a1||a1+2==c1||c1+2==a1||a1+3==c1||c1+3==a1||a1+4==c1||c1+4==a1){
		b2=1;
	}
	cout<<b1<<b2<<b3;
	return 0;
} 
