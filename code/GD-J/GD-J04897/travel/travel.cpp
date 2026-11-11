#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int rx,xx,rpa,xpa,rw,xw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	rx=c1[1]-'0',xx=c2[1]-'0';
	if(c1[0]=='1') rx+=10;
	if(c2[0]=='1') xx+=10;
	if(rx==xx){
		cout<<1;
		rpa=s1[1]-'0',xpa=s2[1]-'0';
		if(s1[0]=='1') rpa+=10;
		if(s2[0]=='1') xpa+=10;
		if(rpa==xpa){
			cout<<1;
			rw=s1[2]-'A'+1,xw=s2[2]-'A'+1;
			if(s1[2]=='F') rw--;
			if(s2[2]=='F') xw--;
			if(rw>xw) swap(rw,xw);
			if((xw==5&&rw==4)||(xw==3&&(rw==2||rw==1))||(xw==2&&rw==1)){
				cout<<1;
				if((xw==5&&rw==4)||(xw==3&&rw==2)||(xw==2&&rw==1)) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
