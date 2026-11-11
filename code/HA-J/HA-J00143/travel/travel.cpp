#include<bits/stdc++.h> 
using namespace std;

string a1,a2,b1,b2;
bool a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		a=1;
	}if(a2[0]==b2[0]&&a2[1]==b2[1]&&a==1){
		b=1;
	}
	char aa=a2[2],bb=b2[2];
	if(aa>='A'&&aa<='C'&&bb>='A'&&bb<='C'&&b==1){
		c=1;
	}else if(aa>='D'&&aa<='E'&&bb>='D'&&bb<='E'&&b==1){
		c=1;
	}if(abs(aa-bb)==1&&c==1){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
