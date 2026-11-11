#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f;
bool ch3(string a,string b){
	int l[7]={0,0,0,0,0,0,0};
	l[a[2]-'A']=1;
	l[b[2]-'A']=1;
	if((l[3]&&l[5]) || (!(l[3]||l[5]))){
		return 1;
	}
	else{
		return 0;
	}
}
bool ch4(string a,string b){
	if(a[2]=='F'){a[2]='E';}
	if(b[2]=='F'){b[2]='E';}
	
	if(abs(a[2]-b[2])==1){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f=1;
	
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	
	if(f && (s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	
	if(f && ch3(s1,s2)){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	
	if(f && ch4(s1,s2)){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	return 0;
}
