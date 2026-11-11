//GZ-J00312,韦胤帆,贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
string x1="";
string x2="";
string s1="";
string s2="";
int f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","ｗ",stdout);
	cin>>x1>>x2>>s1>>s2;
	if(x1==s1) cout<<1;
	else cout<<0;
	if(x2[1]==s2[1]&&x2[0]==s2[0]) cout<<1;
	else cout<<0;
	if(x2[2]<='C'&&s2[2]<='C'||x2[2]>='D'&&s2[2]>='D')
	{
		cout<<1;
		f=1;
	 } 
	else cout<<0;
	if(abs(int(x2[2])-int(s2[2]))==1&&f==1) cout<<1;
	else cout<<0;
	return 0;
}
