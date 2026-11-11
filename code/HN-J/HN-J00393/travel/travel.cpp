#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int a=(s[0]-'0')*10+s[1]-'0',b=(ss[0]-'0')*10+ss[1]-'0';
	if(a==b){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s[2]=='A'&&ss[2]=='B')||(s[2]=='A'&&ss[2]=='C')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0; 
}
