#include<bits/stdc++.h>
using namespace std;
int check(char a,char b){
	if(b=='D'||b=='F'&&a<='C')return 0;
	if(a=='D'||a=='F'&&b<='C')return 0;
	return 1;
}
void check2(int cs,int cs2,char a,char b){
	if(check(a,b)==1){
		if((cs-1==cs2||cs+1==cs2)&&a==b){
			cout<<"1";
		}else if(cs==cs2&&char(a+1)==b||cs==cs2&&(char(a-1)==b))cout<<"1";
		else cout<<"0";	
	}else cout<<"0";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
	cout<<"0000";
	return 0;
	}else cout<<"1";
	int cs=0,cs2=0;
	char a,b;
	for(int i=0;i<3;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			cs=cs*10+s1[i]-'0';
		}else a=s1[i];
		if(s2[i]>='0'&&s2[i]<='9'){
			cs2=cs2*10+s2[i]-'0';
		}else b=s2[i];
	}
	if(cs==cs2)cout<<"1";
	else cout<<"0";
	if(cs==cs2&&check(a,b)==1)cout<<"1";
	else cout<<"0";
	check2(cs,cs2,a,b);
	return 0;
}
