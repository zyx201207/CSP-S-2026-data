#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int n=s1[2]-'A',m=s2[2]-'A';
	if(m<=2&&n<=2){
		cout<<"1";
		if(m-n==1)cout<<"1";
		else cout<<"0";
	}
	else if(m>2&&n>2){
		cout<<"11";
	}
	else cout<<"00";
	return 0;
}
