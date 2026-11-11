#include<bits/stdc++.h>
using namespace std;

string cf,cs,sf,ss;
int ansa,ansb,ansc,ansd;
int a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cf>>sf>>cs>>ss;
	a=sf[0]+sf[1]-'0';
	b=ss[0]+ss[1]-'0';
	c=sf[2]-'0';
	d=ss[2]-'0';
	if(cf==cs){
		ansa=1;
		if(sf[0]+sf[1]==ss[0]+ss[1]){
		    ansb=1;
		    if((sf[2]==ss[2])||(sf[2]-'A'<=2&&ss[2]-'A'<=2)||(sf[2]-'A'>2&&ss[2]-'A'>2)){
			    ansc=1;
			    if((sf[2]==ss[2]&&(a-b==1||a-b==-1))||((a==b&&(c-d==1||c-d==-1)))){
				    ansd=1;
			    }
		    }
	    }
	}
	cout<<ansa<<ansb<<ansc<<ansd;
	return 0;
} 
