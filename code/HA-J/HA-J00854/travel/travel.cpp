#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int s1_,s2_;
	char s10,s20;
	cin>>c1>>s1>>c2>>s2;
	if((c1!=1&&c1!=16)&&(c2!=1&&c2!=16)){
	s1_=(s1[0]-'0')*10+(s1[1]-'0');
	s2_=(s2[0]-'0')*10+(s2[1]-'0');
	s10=s1[2];
	s20=s2[2];
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1_==s2_)&&(c1==c2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1_==s2_)&&(c1==c2)&&(((s10<='C'&&s10>='A')&&(s20<='C'&&s20>='A'))||((s10=='D'||s10=='F')&&(s20=='D'||s20=='F')))){
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1_==s2_)&&(c1==c2)&&(((s10<='C'&&s10>='A')&&(s20<='C'&&s20>='A'))||((s10=='D'||s10=='F')&&(s20=='D'||s20=='F')))){
		if(((s10==s20+1)||(s20==s10+1))&&(!(s10=='C'&&s20=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	}else{
		cout<<0;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
