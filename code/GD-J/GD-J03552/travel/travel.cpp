#include<bits/stdc++.h>
using namespace std;
int num=0,numl=0,r=0,rr=0,len=0,lenl=0;
string s,ss;
bool a=false,b=false,c=false,d=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>num;
	cin>>s;
	cin>>numl;
	cin>>ss;
	len=s.size();
	lenl=ss.size();
	if(num==numl){
		a=true;
	}
	else{
		a=false;
	}
	if(a){
		for(int i=0;i<len-1;i++){
			r=r*10+(s[i]-'0');
		}
		for(int i=0;i<lenl-1;i++){
			rr=rr*10+(ss[i]-'0');
		}
		if(r==rr){
			b=true;
		}
	}
	char t=s[len-1];
	char tt=ss[lenl-1];
	if(a&&b){
		if(t>='A'&&t<='C'&&tt>='A'&&tt<='C'){
			c=true;
		}
		else if(t>='D'&&t<='F'&&tt>='D'&&tt<='F'){
			c=true;
		}
	}
	if(a&&b&&c){
		int g=t-tt;
		if(abs(g)==1){
			d=true;
		}
	}
	
	if(a)	cout<<1;
	else cout<<0;
	
	if(b)	cout<<1;
	else cout<<0;
	
	if(c)	cout<<1;
	else cout<<0;
	
	if(d)	cout<<1;
	else cout<<0;
	cout<<'\n';
	return 0;
}
/*
01 01A 01 01B
0000
*/
