#include<bits/stdc++.h>
using namespace std;
struct ren{
	string s,s_;
	int c,c_;
};
ren x;
struct r{
	string m,m_;
	char c,c_;
};
r p;
string k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x.c>>x.s>>x.c_>>x.s_;
	p.m=p.m+x.s[0]+x.s[1];
	p.m_=p.m_+x.s_[0]+x.s_[1];
	p.c=x.s[2];
	p.c_=x.s_[2];
	if(x.c==x.c_){
		k+="1";
		if(p.m==p.m_){
			k+="1";
			if((p.c>='A'&&p.c<='C')&&(p.c_>='A'&&p.c_<='C')){
				k+="1";
				if((p.c=='A'&&p.c_=='C')||(p.c=='C'&&p.c_=='A')){
					k+="0";
				}
				else{
					k+="1";
				}
			}
			else if((p.c>='D'&&p.c<='F')&&(p.c_>='D'&&p.c_<='F')){
				k+="11";
			}
			else{
				k+="00";
			}
		}
		else{
			k+="000";
		}
	}
	else{
		k+="0000";
	}
	cout<<k;
}
