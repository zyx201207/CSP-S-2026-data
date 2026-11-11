#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	int k1=int(s1[0]-'0')*10+int(s1[1]-'0');
	int k2=int(s2[0]-'0')*10+int(s2[1]-'0');
	char a1=s1[2],a2=s2[2];
	if(k1==k2)cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if((a1>='A'&&a1<='C'&&a2>='A'&&a2<='C')||(a1>='D'&&a1<='F'&&a2>='D'&&a2<='F')){
		cout<<"1";
	}
	else {
		cout<<"00";
		return 0;
	}
	if(abs(int(a1-a2))==1)cout<<"1";
	else cout<<"0";
	 
	return 0;
} 
