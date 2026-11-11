#include<bits/stdc++.h>
using namespace std;
int c1,c2,f[4];
string s1,s2;
char c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) f[0] = 1;
	if(f[0] && s1[0] == s2[0] && s1[1] == s2[1]) f[1] = 1;
	if(f[1] && (s1[2] <= 'C' && s1[2] >= 'A') && (s2[2] <= 'C' && s2[2] >= 'A')) f[2] = 1;
	else if(f[1] && s1[2] <= 'F' && s1[2] >= 'D' && s2[2] <= 'F' && s2[2] >= 'D') f[2] = 1;
	if(f[2] && (s1[2]+1 == s2[2] || s2[2]+1 == s1[2])) f[3] = 1;
	for(int i=0;i<4;i++) printf("%d",f[i]);
	return 0;
}
