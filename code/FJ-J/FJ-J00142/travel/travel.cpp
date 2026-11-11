#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) cout<<1; 
	else cout<<0;
	if(c1 == c2&&s1[0]+s1[1] == s2[0]+s2[1]) cout<<1;
	else cout<<0;
	char a = s1[2];
	char b = s2[2];
	if(c1 == c2&&s1[0]+s1[1] == s2[0]+s2[1]&&(('A'<=a&&a<='C'&&'A'<=b&&b<='C')||('D'<=a&&a<='F'&&'D'<=b&&b<='F'))) cout<<1;
	else cout<<0;
	if(c1 == c2&&s1[0]+s1[1] == s2[0]+s2[1]&&(('A'<=a&&a<='C'&&'A'<=b&&b<='C')||('D'<=a&&a<='F'&&'D'<=b&&b<='F'))&&(((a+1 == b)||(a == b+1)&&('A'<=a&&a<='C'&&'A'<=b&&b<='C'))||((a+1 == b)||(a == b+1)&&('D'<=a&&a<='F'&&'D'<=b&&b<='F')))) cout<<1;
	else cout<<0;
	return 0;
 } 
