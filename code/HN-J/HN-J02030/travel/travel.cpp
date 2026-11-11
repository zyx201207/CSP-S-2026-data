#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int p,f,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if (c1==s1) cout<<1,b=1;
	else cout<<0;
	if (s2[0]==c2[0]&&s2[1]==c2[1]&&b==1)
		cout<<1,a=1;
	else cout<<0;

	if (c2[2]=='A'||c2[2]=='B'||c2[2]=='C')
		p=1;
	if (s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		f=1;
	if (p==f&&a==1&&b==1) cout<<1,a=1,b=1;
	else
		cout<<0;
	if (a==0) {cout<<0;return 0;
	}
	if (c2[2]-s2[2]==1||s2[2]-c2[2]==1&&p==f&&a==1&&b==1) 
		cout<<1;
	else cout<<0;
	return 0;
 } 
