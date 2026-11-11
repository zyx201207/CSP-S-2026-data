#include <iostream>
#include<string>

using namespace std;

string c1,s1,c2,s2;
bool a[10];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a[1]=(c1==c2);
	a[2]=(a[1]&&(s1.substr(0,2)==s2.substr(0,2)));
	a[3]=(a[2]&&(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')));
	a[4]=(a[3]&&s1[2]+1==s2[2]);
	cout<<a[1]<<a[2]<<a[3]<<a[4];
} 
