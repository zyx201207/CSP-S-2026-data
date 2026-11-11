#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=(c1==c2?1:0);
	bool f2=(f1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	bool f3=(f1&&f2&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C' || s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'));
	bool f4=(f1&&f2&&f3&&(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'?1:(s1[2]-'0'-1==s2[2]-'0'||s1[2]-'0'+1==s2[2]-'0'?1:0)));
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
