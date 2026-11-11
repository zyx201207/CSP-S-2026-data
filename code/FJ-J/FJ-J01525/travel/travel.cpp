#include<bits/stdc++.h>
using namespace std;
long long c,cc;
string s,ss;
bool aa(){
	for(long long i=0;i<2;i++){
		if(s[i]!=ss[i]){
			return false;
		}
	}
	return true;
}
bool bb(){
	char c=s[2],cc=ss[2];
	long long x=0,xx=0,xxx=0,xxxx=0;
	for(char i='A';i<='C';i++){
		if(c==i){
			x++;
		}if(cc==i){
			xx++;
		}
	}
	if(x&&xx){
		return true;
	}
	for(char i='D';i<='E';i++){
		if(c==i){
			xxx++;
		}if(cc==i){
			xxxx++;
		}
	}if(xxx&&xxxx){
		return true;
	}
	return false;
}
bool ccc(){
	char c=s[2],cc=ss[2];
	if(c=='D' && cc=='E'){
		return true;
	}
	if(c=='E' && cc=='D'){
		return true;
	}
	if(c=='A' && cc=='B'){
		return true;
	}if(c=='B' && cc=='A'){
		return true;
	}if(c=='B' && cc=='C'){
		return true;
	}if(c=='C' && cc=='B'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(aa()){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(bb()){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(ccc()){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
