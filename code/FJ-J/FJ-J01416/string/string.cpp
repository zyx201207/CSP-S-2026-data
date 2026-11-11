#include<bits/stdc++.h>
using namespace std;
long long a[200005],l[200005]={0};
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0,cnt=0;
	cin>>n;
	string s="";
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	len=s.size();
	if(len%2==0)
	{
		for(long long i=1;i<=len/2;i++)
		{
			for(long long j=len;j>len/2;j--)
			{
				if(s[i]==s[j])
				{
					l[i]=1;
				}
			}
		}
		for(long long i=1;i<=len/2;i++)
		{
			if(l[i]==0)
			{
				cnt++;
			}
		}
	}
	else
	{
		for(long long i=1;i<=len/2;i++)
		{
			for(long long j=len;j>len/2+1;j--)
			{
				if(s[i]==s[j])
				{
					l[i]=1;
				}
			}
		}
		for(long long i=1;i<=len/2;i++)
		{
			if(l[i]==0)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}