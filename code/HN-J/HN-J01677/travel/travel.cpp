#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int f1=0,f2=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	
	if(s1==t1)
	{
		cout<<1;
		if(s2[0]==t2[0]&&s2[1]==t2[1])
		{
			cout<<1;
			if(t2[2]<='C'&&s2[2]<='C'||t2[2]>='D'&&s2[2]>='D')f1=1;
			if(abs((int)(t2[2]-s2[2]))==1&&t2[2]!='C'&&s2[2]!='C'&&f1)f2=1;
		}
		else cout<<0;
	}
	
	else
	{
		cout<<00;
	}
	cout<<f1<<f2;
	return 0;
} 
