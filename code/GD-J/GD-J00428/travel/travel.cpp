#include<bits/stdc++.h> 
using namespace std;
int cn,cm;
string sn,sm,c,ch;
char r,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cn>>sn>>cm>>sm;
		if(cn==cm) cout<<1;
		else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<sn.size();i++){
		if(sn[i]<='9'&&sn[i]>='0'){
		c+=sn[i];
		}else {
			r=sn[i];
		}
	}
		for(int i=0;i<sm.size();i++){
		if(sm[i]<='9'&&sm[i]>='0'){
			ch+=sm[i];
		}else {
			h=sm[i];
		}
	}
	if(c==ch)cout<<1;
	else {
	cout<<0<<0<<0;
	return 0;
}
	if((h=='D'||h=='F')&&(r=='F'||r=='D')) {
	cout<<1<<1;
	return 0;
}
	else if((h=='A'||h=='B'||h=='C')&&(r=='A'||r=='B'||r=='C')) {
	cout<<1;
	if((h=='A'&&r=='B')||(h=='B'&&r=='C')||(h=='B'&&r=='A')||(h=='C'&&r=='B')){
		cout<<1;
	}else cout<<0;
}
	else cout<<0<<0;
	
	return 0;
}
