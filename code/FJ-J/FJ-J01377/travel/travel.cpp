#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b,c,d,e,f;
string s1,s2;
bool abe(){
	if(e==1 && f==1)
		if(abs(c-d)==1)
			return 0;
	else{
		if((c==3 && d==5) || (c==5 && d==3))
			return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	c=s1[2]-'A';d=s2[2]-'A';
	if(c>=0 && c<=2)e=1;
	else e=2;
	if(d>=0 && d<=2)f=1;
	else f=2;
	if(c1!=c2)cout<<"0000";
	else if(a!=b)cout<<"1000";
	else if((e==1 && f==2) || (e==2 && f==1))cout<<"1100";
	else if(abe())cout<<"1110";
	else cout<<"1111";
	return 0;
}
