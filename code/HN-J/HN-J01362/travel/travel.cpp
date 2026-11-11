#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int p1,p2;
	char z1=s1[2],z2=s2[2];
	p1=int(s1[0]-'0')*10+int(s1[1]-'0');
	p2=int(s2[0]-'0')*10+int(s2[1]-'0');
	
	if(c1==c2){
		cout<<1;
	}else {
		cout<<"0000";
		return 0;
	}
	if(p1==p2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(z1<='C'&&z2<='C'||z1>='D'&&z2>='D'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(int(z1-z2)==1||int(z2-z1)==1||z1=='D'&&z2=='F'||z1=='F'&&z2=='D'){
		if(z1=='C'&&z2=='D'||z1=='D'&&z2=='C'){
			cout<<0;
			return 0;
		}else if(z1=='D'&&z2=='F'||z1=='F'&&z2=='D'){
			cout<<1;
		}
		else{
			cout<<1;
		}
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}

