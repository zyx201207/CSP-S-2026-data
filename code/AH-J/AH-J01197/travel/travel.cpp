#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+1;
string c1,s1,c2,s2;
bool cmp(string s,string c){
	int len1=s.size();
	int len2=c.size();
	if(len1!=len2)return 0;
	for(int i=0;i<2;i++){
		if(s[i]!=c[i])return 0;
	}
	return 1;
}
bool sf(string s,string c){
	int lens=s.size();
	int lenc=c.size();
	char s1=s[2];
	char s2=c[2];
	if(s1=='A'&&s2=='B'||s1=='A'&&s2=='C'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='A'||s1=='C'&&s2=='B')return 1;
	return 0;
	
}
bool xl(string s,string c){
	int lens=s.size();
	int lenc=c.size();
	char s1=s[lens-1];
	char s2=c[lenc-1];
	return abs(ll(s1-s2))==ll(1);
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";return 0;
	}
	if(cmp(s1,s2)||cmp(s2,s1))cout<<"1";
	else{
		cout<<"000";return 0;
	}
	if(sf(s1,s2)||sf(s2,s1))cout<<"1";
	else{
		cout<<"00";return 0;
	}  
	if(xl(s1,s2))cout<<"1";
	else cout<<"0";
	return 0;
}
