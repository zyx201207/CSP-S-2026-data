#include<bits/stdc++.h>
using namespace std;

int c1,c2,flag2;string s1,s2;bool flag=1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else{
		cout<<'0';
		flag=0;
	}
	int a1=(s1[0]+s1[1])-'0',a2=(s2[0]+s2[1])-'0';
	if(a1==a2&&flag==1) cout<<'1';
	else{
		cout<<'0';
		flag=0;
	}
	char b1=s1[2],b2=s2[2];
	if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C'&&flag==1){
		cout<<'1';
		flag2=1;
	}
	else if(b1=='D'&&b1=='F'&&b2=='D'&&b2=='F'&&flag==1){
		cout<<'1';
		flag2=2;
	}
	else {
		cout<<'0';
		flag=0;
	}
	if(flag2==1&&flag==1){
		if(b1=='B'){
			cout<<'1';
			return 0;
		}
		if(b2=='B'){
			cout<<'1';
			return 0;
		}
	}
	else if(flag2==2&&flag==1){
		cout<<'1';
		return 0;
	}
	cout<<'0';;
	return 0;
}
