#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trarel.out","w",stdout);
	char a[5],b[5];
	char c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c2>='0'&&c2<='9'){
		a[1]=c2;
	}
	else{
		b[1]=c2;
	}
	if(s2>='0'&&s2<='9'){
		a[2]=s2;
	}
	else{
		b[2]=s2;
	}
	if(c1==s1&&a[1]==a[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		if(c1==s1&&a[1]==a[2]&&(b[1]!=b[2]&&(((b[1]='A'||b[1]='B'||b[1]='C')&&(b[2]='A'||b[2]='B'||b[2]='C'))||((b[1]='D'||b[1]='F')&&(b[2]='D'||b[2]='F'))))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==s1&&a[1]==a[2]&&(b[1]!=b[2]&&(((b[1]='A'||b[1]='B'||b[1]='C')&&(b[2]='A'||b[2]='B'||b[2]='C'))||((b[1]='D'||b[1]='F')&&(b[2]='D'||b[2]='F'))))&&(b[1]='A'&&b[2]='B'||b[1]='B'&&b[2]='A'||b[1]='B'&&b[2]='C'||b[1]='C'&&b[2]='B'&&b[1]='D'&&b[2]='F'||b[1]='F'&&b[2]='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
