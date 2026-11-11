#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int p1,p2,p3,p4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1",p1=1;
	else cout<<"0";
	int s11,s22;
	s11=(s1[0]-'0')*10+(s1[1]-'0');
	s22=(s2[0]-'0')*10+(s2[1]-'0');
	if(s11==s22&&p1)cout<<"1",p2=1;
	else cout<<"0";
	char a,b;
	a=s1[2];
	b=s2[2];
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'&&p1&&p2){
		cout<<"1";
		p3=1;
	}else if(a>='D'&&a<='F'&&b>='D'&&b<='F'&&p1&&p2){
		cout<<"1";
		p3=1;
	}else cout<<"0";
	if(p1&&p2&&p3&&abs(a-b)==1)cout<<"1";
	else cout<<"0";
	
    return 0;
}

