#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char s1_a,s2_a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>s1_a>>c2>>s2>>s2_a;
	if(c1==1||c2==1||c1==16||c2==16){
		cout<<"0000"<<"\n";
		return 0;
	}
	if(c1==c2){
		cout<<1<<"\n";
	}else{
		cout<<"0000"<<"\n";
		return 0;
	}
	if(s1==s2&&c1==c2){
		cout<<1<<"\n";
	}else{
		cout<<"000"<<"\n";
		return 0;
	}
	/*if('c'<=s1_a>='A'){
		if('F'<=s2_a<=)
	}
	*/
	if(     ((('C'<=s1_a>='A')  && ('C'<=s2_a>='A')  )||  (   ('F'<=s1_a>='D') &&('F'<=s2_a>='D') ))&&s1==s2&&c1==c2){
		cout<<1<<"\n";
	}else{
		cout<<"00"<<"\n";
		return 0;
	}
	if(     ((('C'<=s1_a>='A')  && ('C'<=s2_a>='A')  )||  (   ('F'<=s1_a>='D') &&('F'<=s2_a>='D') ))&&s1==s2&&c1==c2&&(abs((s1_a)-(s2_a))=='C'-'B')){
		cout<<1<<"\n";
	}else{
		cout<<0<<"\n";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
