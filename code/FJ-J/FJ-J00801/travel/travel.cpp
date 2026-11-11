#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,s,v;
string i,j,o,k;
char n,m;
bool t,p,h,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>i>>j>>o>>k;
	n=i[0];
	m=i[1];
	a=int((n-'0')*10+(m-'0'));
	n=o[0];
	m=o[1];
	b=int((n-'0')*10+(m-'0'));
	n=j[0];
	m=j[1];
	c=int((n-'0')*10+(m-'0'));
	n=k[0];
	m=k[1];
	d=int((n-'0')*10+(m-'0'));
	s=int(j[2]-'A'+1);
	v=int(k[2]-'A'+1);
	if(a==b){
		t=1;
		if(c==d){
			p=1;
			if(s<=3 && s>=1 && v>=1 && v<=3 && s!=v){
				h=1;
				if(abs(s-v)==1){
					l=1;
				}else{
					l=0;
				}
			}else if(s>=4 && s<=6 && v>=4 && v<=6 && s!=v){
				h=1;
				l=1;
			}else{
				h=0;
				l=0;
			}
		}else{
			p=0;
			h=0;
			l=0;
		}
	}else{
		t=0;
		p=0;
		h=0;
		l=0;
	}
	cout<<t<<p<<h<<l;
	return 0;
} 
