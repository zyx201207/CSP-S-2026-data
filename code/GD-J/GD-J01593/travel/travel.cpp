#include <bits/stdc++.h>
using namespace std;
char a,b,c,d,e;
char na,nb,nc,nd,ne;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d>>e>>na>>nb>>nc>>nd>>ne;
	if((a-'0')*10+b-'0'==(na-'0')*10+nb-'0'){
		cout<<1;
	}else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if((c-'0')*10+d-'0'==(nc-'0')*10+nd-'0'){
		cout<<1;
	}else {
		cout<<0<<0<<0;
		return 0;
	}
	if(e>='A'&&e<='C'&&ne>='A'&&ne<='C'||e>='D'&&e<='F'&&ne>='D'&&ne<='F'){
		cout<<1;
	}else {
		cout<<0<<0;
		return 0;
	}
	if(e=='D'||e=='F'||e==ne-1||e==ne+1){
		cout<<1;
	}else {
		cout<<0;
	}
	return 0;
} 
