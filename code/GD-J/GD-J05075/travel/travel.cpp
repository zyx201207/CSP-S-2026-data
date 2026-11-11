#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p1,p2;
int paishu(string s){
	int n=0;
	n=(s[0]-'0')*10+(s[1]-'0');
	return n;
}
bool istong(string s1,string s2){
	int n1=s1[2]-'A'+1,n2=s2[2]-'A'+1;
	if(n1<=3 && n2>3) return false;
	if(n1>3 && n2<=3) return false;
	return true;
}
bool isai(string s1,string s2){
	int n1=s1[2]-'A'+1,n2=s2[2]-'A'+1;
	return abs(n1-n2)==1 && max(n1,n2)!=4;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(s1[0]==s2[0] && s1[1]==s2[1] && c1==c2) cout<<"1";
	else cout<<"0";
	if(s1[0]==s2[0] && s1[1]==s2[1] && c1==c2 && istong(s1,s2)) cout<<"1";
	else cout<<"0";
	if(s1[0]==s2[0] && s1[1]==s2[1] && c1==c2 && istong(s1,s2) && isai(s1,s2)) cout<<"1";
	else cout<<"0";
	return 0;
}
