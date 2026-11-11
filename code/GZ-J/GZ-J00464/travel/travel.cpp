//GZ_J00464 遵义市第十九中学 刘宇轩 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char x,y;
bool v=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=s1[2];
	y=s2[2];
	if(c1==c2)cout<<1;
	else cout<<0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i])v=false;
	}
	if(c1==c2&&v==true){
		if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='A'||x=='C'&&y=='B'||x=='D'&&y=='F'||x=='F'&&y=='D')cout<<11;
		else cout<<10;
	}else cout<<"00";
	if(v==true){
		if(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B'||x=='D'&&y=='F'||x=='F'&&y=='D')cout<<1;
	    else cout<<0;
	}else cout<<0;
	return 0;
}
