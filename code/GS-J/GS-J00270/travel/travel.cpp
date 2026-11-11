#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[4],s2[4];
int a1=0,a2=0;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[1]>>s1[2]>>s1[3];
	cin>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2){
		cout<<"1";
		a1=s1[1]+'0';
		a1*=10;
		a1+=s1[2]+'0';
		a2=s2[1]+'0';
		a2*=10;
		a2+=s2[2]+'0';
		if(a1==a2){
			cout<<"1";
			ss1=s1[3];
			ss2=s2[3];
			if(ss1=='F'||ss1=='D'){
				if(ss2=='D'||ss2=='F'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else if(ss1=='A'||ss1=='B'||ss1=='C'){
				if(ss2=='B'||ss2=='C'||ss2=='A'){
					cout<<"1";
					if(ss1=='A'&&ss2=='B'){
						cout<<"1";
					}else if(ss1=='B'&&ss2=='C'){
						cout<<"1";
					}else if(ss1=='B'&&ss2=='A'){
						cout<<"1";
					}else if(ss1=='C'&&ss2=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
