#include <bits/stdc++.h>
using namespace std;
bool ist(string s1,string s2){
	int l[10];
	memset(l,0,sizeof(l));
	l[s1[2]-'A']=1;
	l[s2[2]-'A']=1;
	if(l[3]&&l[4])return true;
	if(l[0]+l[1]+l[2]==2)return true;
	return false;
}
bool isp(string s1,string s2){
	int l[10];
	memset(l,0,sizeof(l));
	l[s1[2]-'A']=1;
	l[s2[2]-'A']=1;
	if(l[0]&&l[1])return true;
	if(l[1]&&l[2])return true;
	if(l[3]&&l[4])return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(ist(s1,s2)){
				cout<<1;
				if(isp(s1,s2))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
