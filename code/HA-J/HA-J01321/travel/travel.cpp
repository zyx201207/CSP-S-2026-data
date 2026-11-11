#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int p1=0,p2=0;
	for(int i=0;i<=1;i++){
		p1=p1*10+(s1[i]-'0');
		p2=p2*10+(s2[i]-'0');
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(p1==p2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char si1=s1[2],si2=s2[2];
	if(p1==p2 and ((si1<='C' and si2<='C') or (si1>='D' and si2>='D'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	int a=si1,b=si2;
	if(abs(a-b)==1){
		cout<<1;
	}else{
		cout<<0;
	}

	return 0;
}
