#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?1:0);
	if(c1!=c2){
		cout<<"000";
		return 0;
	}
	string s;
	s+=s1[1];
	s+=s1[0];
	string ss;
	ss+=s2[1];
	ss+=s2[0];
	bool p1=(s==ss);
	cout<<(p1?1:0);
	if(!p1){
		cout<<"00";
		return 0;
	}
	char c11;
	c11=s1[2];
	char c21;
	c21=s2[2];
	bool p=((c11<='C'&&c21<='C')||(c11>='D'&&c21>='D'));
	if(p)cout<<1;
	else cout<<0;
	if(p&&abs((long long)(c11-c21))==1)cout<<1;
	else cout<<0;
	return 0;
} 
