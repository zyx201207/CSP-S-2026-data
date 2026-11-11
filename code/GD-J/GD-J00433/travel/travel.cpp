#include<iostream>
using namespace std;
int c1,s1,c2,s2;
char sp1,sp2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>sp1>>c2>>s2>>sp2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2 and s1==s2)cout<<1;
	else cout<<0;
	if(c1==c2 and s1==s2 and (sp1<='C' and sp2<='C' or sp1>='D' and sp2>='D'))cout<<1;
	else cout<<0;
	if(c1==c2 and s1==s2 and (sp1<='C' and sp2<='C' or sp1>='D' and sp2>='D')){
		if(sp1<='C' and sp2<='C'){
			if(abs(sp1-sp2)==1)cout<<1;
			else cout<<0;
		}
		else cout<<1;		
	}
	else cout<<0;
	return 0;
} 
