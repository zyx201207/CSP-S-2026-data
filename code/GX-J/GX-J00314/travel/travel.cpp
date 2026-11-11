#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int c_k,s_k,cc_k,ss_k,k=1,m;
bool p(){
	if(s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C'){
		m=1;
		return 1;
	}
	if(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F'){
		m=2;
		return 1;
	}
	return 0;
}
bool kk(){
	if(s[2]=='C'&&ss[2]=='D'){
		return 0;
	}
	if(s[2]=='D'&&ss[2]=='C'){
		return 0;
	}
	if(m==1&&abs((s[2]-ss[2])*k)==1){
		return 1;
	}
	if(m==2&&abs((s[2]-ss[2])*k)==2){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	c_k=(c[0]-'0')*10+c[1]-'0';
	s_k=(s[0]-'0')*10+s[1]-'0';
	cc_k=(cc[0]-'0')*10+cc[1]-'0';
	ss_k=(ss[0]-'0')*10+ss[1]-'0';
	if(c_k==cc_k){
		cout<<1;
		if(s_k==ss_k){
			cout<<1;
			if(p()){
				cout<<1;
				if(kk()){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
