#include <bits/stdc++.h>
using namespace std;
long long n,ans,sum;
char s[1111111];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
	    long long a;
		char b;
		cin>>a>>b;
		for(int j=sum+1;j<=sum+a;j++)
		{
			s[j]=b;
		}
		sum+=a;
	}
	for(int i=1;i<=sum/2;i++)
	{
		for(int j=sum;j>sum/2;j--)
		{
			if(s[i]==s[j]) 
			{
				i++;
				j--;
			}
			else {
				ans++;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
