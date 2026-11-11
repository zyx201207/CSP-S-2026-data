//GZ-J00047 贵阳市第一中学 刘一萱 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string c1,s1,c2,s2,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if (s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if (s1[2]>s2[2]){
		s=s1;
		s1=s2;
		s2=s;
	}
	if (s1[2]-'A'<=2 && s2[2]-'A'<=2){
		cout<<1;
	}
	else if (s1[2]-'A'>2 && s2[2]-'A'>2){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if (s1[2]-'A'+1==s2[2]-'A'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
