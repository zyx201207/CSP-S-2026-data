#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ia,ib,ic,id;
char q,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++){
		ia=ia*10+(int)(a[i]-'0');
	}
	for(int i=0;i<c.size();i++){
		ic=ic*10+(int)(c[i]-'0');
	}
	if(ia==ic){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	q=b[2];
	p=d[2];
	for(int i=0;i<2;i++){
		ib=ib*10+(int)(b[i]-'0');
	}
	for(int i=0;i<2;i++){
		id=id*10+(int)(d[i]-'0');
	}
	if(ib==id){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((p>='E'&&q>='E')||(p<='C'&&q<='C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs((int)(p-q))==1){
		cout<<1; 
	}else{
		cout<<"0";
	}
	return 0;
} 
