#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;//a³µÏá£¬a×ùÎ»
	cin>>a1>>a2>>b1>>b2;
	int ax=a1[1]-'0'+a1[0]-'0';
	int bx=b1[1]-'0'+b1[0]-'0';
	if(ax==bx){
		int ay=a2[0]-'0'+a2[1]-'0';
		int by=b2[0]-'0'+b2[1]-'0';
		if(ay==by){
			if((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(a2[2]>='D'&&a2[2]<='F'&&b2[2]>='D'&&b2[2]<='F')){
				if((abs(a2[2]-b2[2])==1)||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}		
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
