#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,p1="",p2="";
	char l1,l2;
	cin>>c1>>s1>>c2>>s2;
	int x=0,y=0,z=0;
	if(c1==c2){
		cout<<1;
		x=1;
	}else{
		cout<<0;
	}
	p1+=s1[0]+s1[1];
	p2+=s2[0]+s2[1];
	l1+=s1[2];
	l2+=s2[2];
	if(x==1&&p1==p2){
		cout<<1;
		y=1;
	}else{
		cout<<0;
	}
	if(x==1&&y==1&&l1<='C'&&l2<='C'){
		cout<<1;
		z=1;
	}else if(x==1&&y==1&&l1>'C'&&l2>'C'){
		cout<<1;
		z=1;
	}else{
		cout<<0;
	}
	if(x==1&&y==1&&z==1&&(l1-l2==1||l2-l1==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
