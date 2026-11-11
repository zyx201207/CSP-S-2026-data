#include <bits/stdc++.h>
using namespace std;
string x,r,xs,rs,s1x,s1r;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>x>>xs>>r>>rs;
	if(x==r){
		cout<<'1';
		for(int i=0;i<=1;i++){
    	s1x+=xs[i];
	}
	for(int i=0;i<=1;i++){
    	s1r+=rs[i];
	}
	if(s1x==s1r){
		cout<<'1';
		if((xs[2]>='A'&&xs[2]<='C'&&rs[2]>='A'&&rs[2]<='C')||(xs[2]>='D'&&xs[2]<='F'&&rs[2]>='D'&&rs[2]<='F')){
		cout<<'1';
		if((char(xs[2]+1)==rs[2]||char(xs[2]-1)==rs[2])&&!((xs[2]=='C'&&rs[2]=='D')||(xs[2]=='D'&&rs[2]=='C'))){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	}
	else{
		cout<<"00";
	}
	
	}
	else{
		cout<<"000";
	}
	
	}
	else{
		cout<<"0000";
	}
    
    return 0;
}
