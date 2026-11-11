#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
inline int pd(const char &c) { return c=='A'||c=='B'||c=='C'; }
inline void print(const string &s) { cout<<s; exit(0); }
main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) print("0000");
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]) print("000");
	cout<<1;
	if(pd(s1[2])!=pd(s2[2])) print("00");
	cout<<1<<(abs(s1[2]-s2[2])==1);
}
