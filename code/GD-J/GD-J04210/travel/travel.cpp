//travel
#include<iostream>
using namespace std;
int func(int x){
	if(x<0)return -x;
	return x;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool scar=0,scrow=0,scrside=0,scrsnei=0;
	if(c1==c2)scar=1;
	if(s1.substr(0,2)==s2.substr(0,2)&&scar)scrow=1;
	char kk1=s1[s1.size()-1],kk2=s2[s2.size()-1];
	if(kk1>='A'&&kk1<='C'&&kk2>='A'&&kk2<='C'&&scrow&&scar)scrside=1;
	if(kk1>='D'&&kk1<='F'&&kk2>='D'&&kk2<='F'&&scrow&&scar)scrside=1;
	if((kk1=='D'&&kk2=='F')||(kk1=='F'&&kk2=='D')){
		if(scar&&scrow&&scrside)scrsnei=1;
	}
	if(func(int(kk1-kk2))==1){
		if((kk1=='C'&&kk2=='D')||(kk1=='D'||kk2=='C'))scrsnei=0;
		else if(scar&&scrow&&scrside)scrsnei=1;
	}
	cout<<int(scar)<<int(scrow)<<int(scrside)<<int(scrsnei);
}