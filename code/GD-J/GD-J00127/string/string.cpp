#include<bits/stdc++.h>
using namespace std;
long long a1[5100000009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	string c,str,str1,str2;
	for(int i=0;i<n;i++)
	{
		cin>>a1[i]>>c;
		for(int j=1;j<=a1[i];j++)
		{
			str+=c;
		}
	}
	int x=str.size();
	if(x%2==0)
	{
		x/=2;
		for(int i=0;i<x;i++)
		{
			str1+=str[i];
			str2+=str[x*2-1-i];
		}
		for(int i=0;i<x;i++)
		{
			if(str1[i]!=str2[i])
			{
				if(a1[i]>=a1[x*2-1-i])
				{
					str2[i]=str1[i];
				}
				else
				{
					str1[i]=str2[i];
				}
				ans++;
			}	
		}		
	}
	if(x%2!=0)
	{
		x=(x-1)/2;
		for(int i=0;i<x;i++)
		{
			str1+=str[i];
			str2+=str[x*2-i];
		}
		for(int i=0;i<x;i++)
		{
			if(str1[i]!=str2[i])
			{
				
				if(a1[i]>a1[x*2-i])
				{
					str2[i]=str1[i];
				}
				else
				{
					str1[i]=str2[i];
				}
				ans++;
			}	
		}
	}
	cout<<ans<<"\n";
	return 0;
}
