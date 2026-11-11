#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int a;
int b;
int c;
int d;
char num1,num2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//1.
	for(int i=0;i<2;i++){
		a*=10;
		a+=c1[i]-'0';
	}
	for(int i=0;i<2;i++){
		b*=10;
		b+=c2[i]-'0';
	}
	if(a==b) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	//2.
	for(int i=0;i<2;i++){
		c*=10;
		c+=s1[i]-'0';
	}
	for(int i=0;i<2;i++){
		d*=10;
		d+=s2[i]-'0';
	}
	if(c==d) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	//3.
	num1=s1[2];
	num2=s2[2];
	if(num1>='A'&&num1<='C'&&num2>='A'&&num2<='C'||num1>='D'&&num1<='F'&&num2>='D'&&num2<='F') cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	//4.
	if(abs(num1-num2)==1) cout<<"1";
	else cout<<"0";
	return 0;
} 
