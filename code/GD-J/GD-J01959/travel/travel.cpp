#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int na,nb;
string a,b,c,d;
char nc,nd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	for(int i=0;i<2;i++){
		na=na*10+c[i]-'0';
	    nb=nb*10+d[i]-'0';
	}
	nc=c[2];
	nd=d[2];
	if(a==b) cout<<1;
	else cout<<0;
	 if(a==b&&na==nb) cout<<1;	
	else cout<<0;
	if(a==b&&na==nb&&((nc<='B'&&nd<='B')||(nc>='C'&&nd>='C'))) cout<<1;
	else cout<<0;
	if(a==b&&na==nb&&((nc<='B'&&nd<='B')||(nc>='C'&&nd>='C'))&&((char(nc+1)==nd)||(char(nd+1)==nc))) cout<<1;
	else cout<<0; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
