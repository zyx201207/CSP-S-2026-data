#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,len=0;
	string s,a;
	long long  num=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m>>a;
		for(int j=0;j<m;j++)
		{
			s+=a;
			len++;
		}
	}
	if(len%2==0)
	{
		for(int i=0;i<len/2;i++)
		{
			if(s[i]!=s[i+len/2])
			{
				num++;
			}
		}
	}else{
		for(int i=0;i<len/2;i++)
		{
			if(s[i]!=s[i+len/2+1])
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
