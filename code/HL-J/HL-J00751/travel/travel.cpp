#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool f1,f2,f3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    string a,b;
    a=a2.substr(0,2);
    b=b2.substr(0,2);
    if(a1==b1){
    	cout<<1;
    	f1=1;
	}else{
		cout<<0;
	}
	if(f1&&a==b){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	if(f1&&f2&&((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(a2[2]>='D'&&a2[2]<='F'&&b2[2]>='D'&&b2[2]<='F'))){
		cout<<1;
		f3=1;
	}else{
		cout<<0;
	}
	if(f1&&f2&&f3&&((a2[2]=='B'||b2[2]=='B')||(a2[2]=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}
