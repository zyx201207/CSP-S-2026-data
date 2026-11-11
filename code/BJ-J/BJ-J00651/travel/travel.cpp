#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
bool pd(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C'){
			return true;
		}else return false;
	}
	if(a=='B'){
		if(b=='A'||b=='C'){
			return true;
		}else return false;
	}
	if(a=='C'){
		if(b=='A'||b=='B'){
			return true;
		}else return false;
	}
	return false;
}
bool xl(char g1,char g2){
	if(g1=='A'){
		if(g2=='B'){
			return true;
		}else{
			return false;
		}
	}
	if(g1=='B'){
		if(g2=='C'||g2=='A'){
			return true;
		}else{
			return false;
		}
	}
	if(g1=='C'){
		if(g2=='B'){
			return true;
		}else{
			return false;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int getc1,getc2,gets1,gets2;
	char g1=s1[2],g2=s2[2];
	getc1=(c1[0]-'0')*10+(c1[1]-'0');
	getc2=(c2[0]-'0')*10+(c2[1]-'0');
	if((getc1==getc2)){
		cout<<1;
		gets1=(s1[0]-'0')*10+(s1[1]-'0');
		gets2=(s2[0]-'0')*10+(s2[1]-'0');
		if(gets1==gets2){
			cout<<1;
			if(((g1=='F'&&g2=='D')||(g1=='D'&&g1=='F'))||(pd(g1,g2)&&pd(g2,g1))){
				cout<<1;
				if((g1=='F'&&g2=='D')||(g1=='D'&&g1=='F')){
					cout<<1;
				}else if(xl(g1,g2)&&xl(g2,g1)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
