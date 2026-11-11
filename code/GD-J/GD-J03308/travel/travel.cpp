#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string xn,xm; 
int xnn,xmm;
int xn1,xm1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	xn=c1;
	xm=c2;
	xnn=(s1[0]-'0')*10+(s1[1]-'0');
	xmm=(s2[0]-'0')*10+(s2[1]-'0');
	xn1=s1[2]-'A';
	xm1=s2[2]-'A';
	if(xn==xm){
		cout<<"1";
		if(xnn==xmm){
			cout<<"1";
			if(xn1>=0&&xn1<=2&&xm1>=0&&xm1<=2){
				cout<<"1";
				if(xn1==xm1&&(xnn=xmm-1||xnn==xmm+1)){
					cout<<"1";
				} 
				else if((xn1-1==xm1||xn1+1==xm1)&&xnn==xmm){
					cout<<"1";
				} 
				else{
					cout<<"0";
				
				}
			}
			else if(xn1>=3&&xn1<=5&&xm1>=3&&xm1<=5){
				cout<<"1";
				if(xn1==xm1&&(xnn=xmm-1||xnn==xmm+1)){
					cout<<"1";
				} 
				else if((xn1-2==xm1||xn1+2==xm1)&&xnn==xmm){
					cout<<"1";
				} 
				else{
					cout<<"0";
				
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
