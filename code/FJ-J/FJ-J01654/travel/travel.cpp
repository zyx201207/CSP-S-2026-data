#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ol,tl,oh,th;
char ow,tw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]=='0'){
		ol=c1[1]-'0';
	}else{
		ol=(c1[0]-'0')*10+(c1[1]-'0');
	}if(c2[0]=='0'){
		tl=c2[1]-'0';
	}else{
		tl=(c2[0]-'0')*10+(c2[1]-'0');
	}
	if(ol!=tl){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
	}
	if(s1[0]=='0'){
		oh=s1[1]-'0';
	}else{
		oh=(s1[0]-'0')*10+(s1[1]-'0');
	}if(s2[0]=='0'){
		th=s2[1]-'0';
	}else{
		th=(s2[0]-'0')*10+(s2[1]-'0');
	}if(th!=oh){
		cout<<"000";
		return 0;
	}else{
		cout<<'1';
	}
	ow=s1[2],tw=s2[2];
	if((ow<='C'&&tw<='C')||(ow>='D'&&tw>='D')){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(ow-1==tw||tw-1==ow){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
