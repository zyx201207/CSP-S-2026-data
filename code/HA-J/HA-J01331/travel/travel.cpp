#include  <bits/stdc++.h>
using namespace  std;
int jian(char x,char y){
	if(x>y){
		return (x-'A')-(y-'A') ;
	}else{
		return (y-'A')-(x-'A') ;
	}
}
int main( ){
	freopen (trauel.in,"r",stdin);
	freopen (trauel.out,"w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
		cout<<1;
	}else  if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
		cout<<1;
		cout<<1;
		return 0;
	}else{
		cout<<0;
	}
	char a,b;
	a=s1[2];
	b=s2[2];
	if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
	if(jian(a,b)==1){
		cout<<1;
	}else{
		cout<<0;
	}}else{
		cout<<0;
	}
	
	return 0;
}
