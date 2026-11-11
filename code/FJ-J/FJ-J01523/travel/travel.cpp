#include<bits/stdc++.h>
using namespace std;
bool work(string s1,string s2){
	long long x=s1[1]-'0',y=s2[1]-'0';
	if(s1[0]==1) x+=10;
	if(s2[0]==1) y+=10;
	if(x==y) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(work(s1,s2)==true){
			cout<<"1";
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') cout<<"11";
			else{
				if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A') cout<<"10";
				else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C')) cout<<"11";
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
