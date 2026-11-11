#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool c=1,s=1;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i]) c=0;
		if(s1[i]!=s2[i]) s=0;
	}
	if(c)cout<<"1";
	else
	{
	   cout<<"0000";
	   return 0;
	}
	if(s)cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	 } 
	 if(s1[2]>='D'&&s2[2]>='D') cout<<"1";
	 else if(s1[2]<'D'&&s2[2]<'D') cout<<"1";
	 else
	 {
	 	cout<<"00";
	 	return 0;
	 }
	 int maxn=max(s1[2],s2[2]),minn=min(s1[2],s2[2]);
	 if(maxn-minn==1)cout<<"1";
	 else cout<<"0";
	return 0;
 } 
