#include<bits/stdc++.h>
using namespace std;
int n,a,f=-1;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s+=c;
		}
	}
	int l1=s.size();
	int l2=l1/2;
	for(int i=0;i<l2-1;i++)
	{
		for(int j=l1-i-1;j>l1-i-2;j--)
		{
			if(s[i]!=s[j])
				f=0;
		}
	}
	if(f==-1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<l2;i++)
	{
		for(int j=l1;j>=l2-1;j--)
		{
			if(s[i]=!s[j])
			{
				s[j]=s[i];
				f+=1;
			}
		}
	}
	cout<<f;
	return 0;
}
