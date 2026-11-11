#include<bits/stdc++.h>
using namespace std;
	long long n;
	string s;
	string s2;
	long long sum=0;
	long long z=s.size();
    long long f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1) cout<<0;
	int l=0;
		for(int i=0;i<n;i++)
		{
			int m;
			string a;
			cin>>m>>a;
			for(int j=1;j<=m;j++)
			{
				s+=a;
			}
		}
	if(s.size%2!=0)
	{
		f=s.size()/2+1;
	}
	else
	{
		f=s.size()/2;
	}
	for(int i=1;i<=s.size();i++);
	{
		s2+='a';
	}
	for(int i=1;i<=f;i++)
	{
		if(s2[i]!=s[i])
        {
        	
	        if(s2[h-1]!=s[i])
		    {
		    	s[h-i]=s[i];
			    sum++;
		    }
	    }
	}
	cout<<sum;
	return 0;
}
