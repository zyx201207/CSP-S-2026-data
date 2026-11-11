#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int ans[10000];
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}else{
		a=0;
	};
	if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		b=1;
	}else{
		b=0;
	};
	if(a,b==1&&'A'<=s1[2]<='C'&&'A'<=s2[2]<='C'){
		c=1;
	}else if(a,b==1&&s1[2]=='D'&&s2[2]=='F'){
		c=1;
	}else{
		c=0;
	}
	if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
		d=1;
	}else if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s2[2]=='B'&&s1[2]=='C'){
		d=1;
	}else{
		d=0;
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
