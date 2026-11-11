#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	int x,y;
	x=(s1[0]-'0')*10+s1[1]-'0';
	y=(s2[0]-'0')*10+s2[1]-'0';
	if(x==y){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	x=s1[2]-'A'+1;
	y=s2[2]-'A'+1;
	if(x<=3&&y<=3||x>3&&y>3){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(x-y)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
