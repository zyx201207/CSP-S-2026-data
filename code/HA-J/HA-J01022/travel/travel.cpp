#include<bits/stdc++.h>
using namespace std;
string oc,oy,tc,ty;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>oc>>oy>>tc>>ty;
	if(oc!=tc){
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	if(oy[0]!=ty[0]||oy[1]!=ty[1]){
		cout<<'1'<<'0'<<'0'<<'0';
		return 0;
	}
	if((oy[2]=='F'&&ty[2]=='C')||(oy[2]=='F'&&ty[2]=='B')||(oy[2]=='F'&&ty[2]=='A')||(oy[2]=='D'&&ty[2]=='C')||(oy[2]=='D'&&ty[2]=='B')||(oy[2]=='D'&&ty[2]=='A')||(ty[2]=='F'&&oy[2]=='C')||(ty[2]=='F'&&oy[2]=='B')||(ty[2]=='F'&&oy[2]=='A')||(ty[2]=='D'&&oy[2]=='C')||(ty[2]=='D'&&oy[2]=='B')||(ty[2]=='D'&&oy[2]=='A')){
		cout<<'1'<<'1'<<'0'<<'0';
		return 0;
	}
	if((oy[2]=='C'&&ty[2]=='A')||(ty[2]=='C'&&oy[2]=='A')){
		cout<<'1'<<'1'<<'1'<<'0';
		return 0;
	}
	cout<<'1'<<'1'<<'1'<<'1';
	return 0;
} 
