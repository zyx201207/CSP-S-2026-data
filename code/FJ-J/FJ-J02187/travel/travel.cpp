#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char ans[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
	ans[0]='1';
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
	ans[1]='1';
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
	ans[2]='1';
	if(abs(s1[2]-s2[2])==1)
	 ans[3]='1';
	else
	 ans[3]='0';
			}
	else
	 {ans[2]='0';ans[3]='0';}
		}
	else 
	 {ans[1]='0';ans[2]='0';ans[3]='0';}
	}
	else 
	 for(int i=0;i<4;i++)
	  ans[i]='0';
	for(int i=0;i<4;i++)
	 cout<<ans[i];
}