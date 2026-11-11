//贵阳市第十八中学 刘文浩 GZ-J00572
#include<bits/stdc++.h>
using namespace std;
bool kk(char x,char y){
	if(x=='A'&&(y=='B'||y=='C')) return 1;
	else if(x=='B'&&(y=='A'||y=='C')) return 1;
	else if(x=='C'&&(y=='A'||y=='B')) return 1;
	else if(x=='D'&&y=='F') return 1;
	else if(x=='F'&&y=='D') return 1;
	return 0;
}
bool f(char x,char y){
	if(x=='F'&&y=='D') return 1;
	else if(x=='D'&&y=='F') return 1;
	else if(x=='A'&&y=='B') return 1;
	else if(x=='B'&&y=='A') return 1;
	else if(x=='C'&&y=='B') return 1;
	else if(x=='B'&&y=='C') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
		cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int ss1=(s1[0]-'0')*10+(s1[1]-'0'),ss2=(s2[0]-'0')*10+(s2[1]-'0');
	char zw1=s1[2],zw2=s2[2];
	if(ss1==ss2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(kk(zw1,zw2)==1) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(f(zw1,zw2)==1) cout<<1;
	else cout<<0;
	return 0;
}
