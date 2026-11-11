#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char ch1,ch2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(ch1=='D'){
		ch1++;
	}
	if(ch2=='D'){
		ch2++;
	}
	if((ch1<='C' && ch2<='C') || (ch1>='E' && ch2>='E')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(ch1-ch2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
