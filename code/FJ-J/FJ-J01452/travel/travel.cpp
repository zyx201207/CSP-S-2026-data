#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int find(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	if(c=='D'||c=='F')return 2;
}
signed main(){
  	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	string sa,sb;
	
	sa=s1[0]+s1[1];
	sb=s2[0]+s2[1];
	if(sa==sb)cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if(find(s1[2])==find(s2[2]))cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(find(s1[2])==2&&find(s2[2])==2)cout<<"1";
	else if(string()+s1[2]+s2[2]=="AC"
		||string()+s1[2]+s2[2]=="CA"){
		cout<<"0";
	}else cout<<"1";
	return 0;
}

