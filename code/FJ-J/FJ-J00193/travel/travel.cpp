#include<bits/stdc++.h>
using namespace std;
string sx1,sx2,sy1,sy2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sx1>>sx2>>sy1>>sy2;
	if(sx2[2]=='D') sx2[2]='E';
	if(sy2[2]=='D') sy2[2]='E';
	a=1,b=1,c=1,d=1;
	for(int i=0;i<sx1.size();i++){
		if(sx1[i]!=sy1[i]) a=0;
	}
	if(a==0) b=0,c=0,d=0;
	else{
		if(sx2[0]!=sy2[0]||sx2[1]!=sy2[1]) b=0;
		if(b==0) c=0,d=0;
		else{
			if(sx2[2]<='C'&&sy2[2]>='E'||sx2[2]>='E'&&sy2[2]<='C') c=0;
			if(c==0) d=0;
			else{
				int o,p;
				o=sx2[2]-'A';
				p=sy2[2]-'A';
				if(abs(o-p)!=1) d=0;
			}
		}
	}
	if(a==1) cout<<1;
	else cout<<0;
	if(b==1) cout<<1;
	else cout<<0;
	if(c==1) cout<<1;
	else cout<<0;
	if(d==1) cout<<1;
	else cout<<0;
	
	return 0;
}
