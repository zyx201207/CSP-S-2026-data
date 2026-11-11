#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("travel1.in","u",stdin);
	//freopen("travel1.out","w",stdout);
	int c1,s1;
	string c2,s2;
	cin>>c1>>c2>>s1>>s2;
	int x=0;
	if(c1==s1)
		cout<<1;
	else
		cout<<0;
	if(c2[0]*10+c2[1]==s2[0]*10+s2[1])
		cout<<1;
	else
		cout<<0;
	if((s2[2]<='C'&&c2[2]<='C')||(s2[2]>='D'&&c2[2]>='D'))
		cout<<1;
	else
		cout<<0;
	int a=c2[2]-'A',b=s2[2]-'A';
	if(a-b==1||a-b==-1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
