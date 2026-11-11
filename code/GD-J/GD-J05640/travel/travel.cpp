#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

string a,b,aa,bb,na,nb;
char n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	na=a;
	na.erase(2);
	nb=b;
	nb.erase(2);
	if(na==nb){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	n=aa[2];
	m=bb[2];
	if((m<'D'&&n<'D')||(m>'C'&&n>'C')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((n=='D'&&m=='F')||(m=='D'&&n=='F')||(m=='B'&&n=='A')||(m=='B'&&n=='C')||(m=='C'&&n=='B')||(m=='A'&&n=='B')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
