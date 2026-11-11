#include<bits/stdc++.h>
using namespace std;
int a,b,a3,b3;
string a1,b1;
char a2,b2;
bool gd(char x,char y){
	if(x=='A'&&(y=='B'||y=='C')) return 1;
	if(x=='B'&&(y=='A'||y=='C')) return 1;
	if(x=='C'&&(y=='A'||y=='B')) return 1;
	if(x=='D'&&y=='F') return 1;
	if(x=='F'&&x=='D') return 1;
	return 0;
}
bool xl(char x,char y){
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&(y=='A'||y=='C')) return 1;
	if(x=='C'&&y=='B') return 1;
	if(x=='D'&&y=='F') return 1;
	if(x=='F'&&x=='D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1;
	cin>>b>>b1;
	a2=a1[2],b2=b1[2];
	a3=(a1[0]-'0')*10+(a1[1]-'0');
	b3=(b1[0]-'0')*10+(b1[1]-'0');
	if(a==b){
		cout<<"1";
		if(a3==b3){
			cout<<"1";
			if(gd(a2,b2)==1){
				cout<<"1";
				if(xl(a2,b2)==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";		
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
