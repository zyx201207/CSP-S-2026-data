#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","R",stdin);
	freopen("travel.out","W",stdout);
	char c1,c2,s1,s2,e,f;
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=3;i++){
		if(c1>='0'&&c1<='9'){
			a=c1-'0';
		}
		if(c2>='0'&&c2<='9'){
			b=c2-'0';
		}
		if(s1>='0'&&s1<='9'){
			c=s1-'A'-'0';
		}
		if(s2>='0'&&s2<='9'){
			d=s2-'A'-'0';
		}
		if(s1>='A'&&s1<='F'){
			e=s1-'A'+1;
			
		}
		if(s2>='A'&&s2>='F'){
			f=s2-'A'+1;
		}
	}
	
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c==d){
		cout<<"1";	
	}else{
		cout<<"0";
	}
	if(e<='C'&&e>='A'&&f<='C'&&f>='A'||e>='D'&&e<='F'&&f<='F'&&f>='D'){
		cout<<"1";	
	}else{
		cout<<"0";
	}
	if(e+1==f&&e!='C'&&f!='D'&&e!='D'&&f!='C'){
		cout<<"1";
		
	}else{
		cout<<"0";
	}
	
	return 0;
}
