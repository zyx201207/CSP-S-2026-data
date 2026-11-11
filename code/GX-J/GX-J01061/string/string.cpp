#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	bool flag=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		string st,s1t;
		cin>>a>>st;
		if(s1t!=st)
		{
			flag=1;
		}
		s1t=st;
		for(int i=0;i<a;i++)
		{
			s=s+st;
		}
	}
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	long long num=0,s1=s.size();
	if(s1%2==1)
	{
		long long l=s1/2,r=s1/2;
		for(long long i=0;i<s1/2;i++)		
		{
			
			l--;
			r++;
			char le=s[l],ri=s[r];
			if(le!=ri)
			{
				num++;
			}
			
		}
	}
	if(s1%2==0)
	{
		long long l=s1/2-1,r=s1/2;
		for(long long i=0;i<s1/2;i++)		
		{
			
			l--;
			r++;
			char le=s[l],ri=s[r];
			if(le!=ri)
			{
				num++;
			}
			
		}
	}
	cout<<num;
	return 0;
}
