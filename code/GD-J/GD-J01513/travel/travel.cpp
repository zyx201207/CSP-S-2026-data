#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1,f2,f3,f4;
	if(c1==c2)f1=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2))f2=1;
	else f2=0;
	if(f2==1&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')))f3=1;
	else f3=0;
	if(f2==1&&f3==1&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')
					||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F')))f4=1;
	else f4=0;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
