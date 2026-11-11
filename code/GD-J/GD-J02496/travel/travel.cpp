#include<bits/stdc++.h>
using namespace std;
bool same(char a,char b){
	char x[]={'A','B','C','D','F'};
	if(a=='C'&&b=='D'||a=='D'&&b=='C')return 0;
	for(int i=0;i<5;i++){
		if(a==x[i]&&(b==x[i+1]||b==x[i-1]))return 1;
	} 
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool sx=0,sh=0,sc=0;
	int s1_=0,s2_=0;
	for(int i=0;i<2;i++){
		s1_=10*s1_+s1[i]-'0';
		s2_=10*s2_+s2[i]-'0';
	}
	char s1a=s1[2],s2a=s2[2];
	if(c1==c2){
		sx=1;
		cout<<1;
	}else cout<<0;
	if(sx&&s1_==s2_){
		sh=1;
		cout<<1;
	}else cout<<0;
	if(sh&&((s1a>='A'&&s1a<='C'&&s2a>='A'&&s2a<='C')||((s1a=='D'||s1a=='F')&&(s2a=='D'||s2a=='F')))){
		sc=1;
		cout<<1;
	}else cout<<0;
	if(sx&&sh&&same(s1a,s2a))cout<<1;
	else cout<<0;
	return 0;
}
