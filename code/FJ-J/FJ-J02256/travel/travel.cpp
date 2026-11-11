#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
bool check(char a,char b){
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')return 1;
	if(a>='D'&&a<='F'&&b>='D'&&b<='F')return 1;
	return 0;
}
bool check1(char a,char b){
	char c=min(a,b),d=max(a,b);
	if(c=='A'&&d=='B')return 1;
	if(c=='B'&&d=='C')return 1;
	if(c=='D'&&d=='F')return 1; 
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;	
	} 
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	} 
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&check(s1[2],s2[2])){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	} 
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&check(s1[2],s2[2])&&check1(s1[2],s2[2])){
		cout<<1;
	}else cout<<0;
	return 0;
} 
