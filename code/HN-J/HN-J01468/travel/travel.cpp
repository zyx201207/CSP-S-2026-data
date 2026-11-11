#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool o=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		o=true;
		cout<<'0';
	}else cout<<'1';
	if(s1[0]!=s2[0]||s1[1]!=s2[1]||o){
		cout<<'0';
		o=true;
	}else cout<<'1';
	if((s1[2]<'D'&&s1[2]>'C')||(s1[2]>'C'&&s1[2]<'D')||o){
		cout<<'0';
		o=true;
	}else cout<<'1';
	if(abs(s1[2]-s2[2])!=1||o){
		cout<<'0';
		o=true;
	}else cout<<'1';
	return 0;
}

