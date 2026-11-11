#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char a;
		long long b;
		cin>>b>>a;
		for(int j=0;j<b;j++)
		{
			s+=a;
		}
	}
	long long cnt=0;
	bool flag=0;
	for(long long j=0;;j++)//判断关于回文数是否成立，成立则结束循环 
	{
		for(long long i=0;i<sizeof(s)/2;i++)
		{
			if(s[i]!=s[sizeof(s)])
			{
				break;
			}
			else
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			break;
		}
		s[sizeof(s)/2+j]=s[j];
		cnt++;
	}
	cout<<cnt;
	return 0;
}
