#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool d=(c1==c2);
	if(d)putchar('1');else putchar('0');
	bool g=(s1[0]==s2[0]&&s1[1]==s2[1]);
	if(g&&d)putchar('1');else putchar('0');
	bool f=((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'));
	if(d&&g&&f)putchar('1');else putchar('0');
	int x=abs(s1[2]-s2[2]),y=abs(((s1[0]-'0')*10+s1[1]-'0')-((s2[0]-'0')*10+s2[1]-'0'));
	if(d&&f&&((x==1&&y==0)||x==0&&y==1))putchar('1');else putchar('0');
	return 0;
}
