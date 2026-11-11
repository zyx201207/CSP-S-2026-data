#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a,b,sa,hb;
string s,h,bl="0000";
char ch;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>h;
	if(s[2]=='F')
		s[2]='E';
	if(h[2]=='F')
		h[2]='E';
	sa=int(s[0]-'0')*10+int(s[1]-'0');
	hb=int(h[0]-'0')*10+int(h[1]-'0');
	if(a==b){
		bl[0]='1';
		if(hb==sa){
			bl[1]='1';
			a=int(s[2]-'A'+1);
			b=int(h[2]-'A'+1);
			if((a<=3&&b<=3)||(a>3&&b>3)){
				bl[2]='1';
				if(a<b){
					int t=b;
					b=a;
					a=t;
					ch=s[2];
					s[2]=h[2];
					h[2]=ch;
				}
				if(a-b==1&&s[2]!='D')
					bl[3]='1';
			}	
		}	
	}
	cout<<bl;
	return 0;
}
