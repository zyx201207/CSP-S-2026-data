#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3,f4;
bool pd(char ch)
{
	if(ch=='A'||ch=='B'||ch=='C') return 0;
	else return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s1,s2;
	int c1,c2;
	f1=f2=f3=f4=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1=1;
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1]) f2=1;
	if(f2&&pd(s1[2])==pd(s2[2])) f3=1;
	if(f3&&(s1[2]!='A'||s2[2]!='C')&&(s1[2]!='C'||s2[2]!='A')) f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
