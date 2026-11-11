//鲁卓然 贵阳市第十八中学 GZ-J00236 
#include<bits/stdc++.h>
using namespace std;
bool oneside(char a,char b)
{
 	 if((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C')) return 1;
	 else if((a == 'D' || a == 'F') && (b == 'D' || b == 'F')) return 1;
	 return 0; 
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) cout<<1;
	else cout<<0;
	int x1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int x2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(x1 == x2 && c1 == c2) cout<<1;
	else cout<<0;
	if(x1 == x2 && c1 == c2 && oneside(s1[2],s2[2])) cout<<1;
	else cout<<0;
	if(x1 == x2 && c1 == c2 && oneside(s1[2],s2[2]) && (abs(s1[2] - s2[2]) == 1)) cout<<1;
	else cout<<0;
	return 0;
}
