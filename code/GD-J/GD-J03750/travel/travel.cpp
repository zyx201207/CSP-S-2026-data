#include<bits/stdc++.h>
using namespace std;
int a1,a2;
int s1,s2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>b1>>a2>>s2>>b2;
	if(a1==a2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1==s2&&((b1>='D'&&b2>='D') || (b1<='C'&&b2<='C'))){
		cout<<"1";
		if(b1-b2==1||b2-b1==1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	else{
		cout<<"00";
		return 0;
	}
	return 0;
}
