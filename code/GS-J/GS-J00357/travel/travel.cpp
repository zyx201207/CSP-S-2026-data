#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2,a1,a2;
	char x,y;
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0];
	a1+=s1[1];
	a2=s2[0];
	a2+=s2[1];
	x=s1[2];
	y=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else if(a1!=a2){
		cout<<"1000";
		return 0;
	}else if((x=='A'&&(y=='B'||y=='C')||(x=='B'&&(y=='A'||y=='C'))||(x=='C'&&(y=='B'||y=='A'))||(x=='D'&&y=='F')||(x=='F'&&y=='D'))){
			if((x=='A'&&y=='B'||(x=='B'&&(y=='A'||y=='C'))||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))){
				cout<<"1111";
				return 0;
			}else{
			cout<<"1110";
			return 0;
			}
	}else{
		cout<<"1100";
		return 0;
		}
}

