#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		int geshu;
		char zm;
		cin>>geshu>>zm;
		if(geshu>1e6)
		{
			flag=false;
			geshu/=1e6;
		}
		for(int j=0;j<geshu;j++)
		{
			s+=zm;
		}
	}
	string ss="";
	for(int i=s.size()-1;i>=0;i--)
	{
		ss+=s[i];
	}
	long long sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(ss[i]!=s[i])
		{
			sum++;
		}
	}
	if(flag==false)
	{
		cout<<sum/2*1000000;
	}
	else
	{
		cout<<sum/2;	
	}
	
	return 0;
}
