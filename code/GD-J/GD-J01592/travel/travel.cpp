#include<bits/stdc++.h>
using namespace std;
string s;
int len,ans,m;
string a1,a111,b1,b111,a11,b11;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a111>>b1>>b111;
	a11+=a111[0];
	a11+=a111[1];
	b11+=b111[0];
	b11+=b111[1];
	a=a111[2];
	b=b111[2];
	if(a1==b1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a11==b11){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a11==b11 && ((a<='C' && a>='A'&& b<='C'&& b>='A')||(a<='F' && a>='D'&& b<='F'&& b>='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a11==b11 && (a+1==b || b+1==a)){
		if((a=='C' && b=='D') || (b=='C' && a=='D'))
		{
			cout<<"0";
			return 0;
		}
		cout<<"1";
	}else{
		if((a=='F' && b=='D') || (b=='F' && a=='D'))
		{
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
