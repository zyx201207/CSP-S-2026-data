#include<bits/stdc++.h>
using namespace std;
//I Love CCF
bool b[4];
int c1,c2;
string s1,s2;
int s1q,s2q;
char s1h,s2h;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	s1q=(s1[0]-'0')*10+s1[1]-'0';
	s2q=(s2[0]-'0')*10+s2[1]-'0';
	s1h=s1[2];
	s2h=s2[2];
	b[0]=(c1==c2);
	b[1]=b[0]&&(s1q==s2q);
	b[2]=b[1]&&((s1h<='C'&&s2h<='C')||(s1h>'C'&&s2h>'C'));
	b[3]=b[2]&&((s1h=='D'&&s2h=='F')||(s1h=='F'&&s2h=='D')||(s1h=='A'&&s2h=='B')||(s1h=='B'&&s2h=='A')||(s1h=='B'&&s2h=='C')||(s1h=='C'&&s2h=='B'));
	for(int i=0;i<4;i++)cout<<b[i];
	return 0;
}
