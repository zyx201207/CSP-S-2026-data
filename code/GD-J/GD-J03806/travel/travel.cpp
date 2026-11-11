#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s!=s2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int is_tong=1;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s3[i]&&s1[i]>='0'&&s1[i]<='9')
		{
			is_tong=0;
			break;
		} 
	}
	if(is_tong==0)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(s1[s1.size()-1]>='A'&&s1[s1.size()-1]<='C')
	{
		if(s3[s3.size()-1]>='A'&&s3[s3.size()-1]<='C')cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(abs(s1[s1.size()-1]-s3[s3.size()-1])==1)cout<<"1";
	else cout<<"0";
 } 
