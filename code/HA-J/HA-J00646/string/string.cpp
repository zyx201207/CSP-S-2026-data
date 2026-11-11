#include<bits/stdc++.h>
using namespace std;
long long s[200005],s1[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	int i=1,j=n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>s[i]>>c;
		s1[i]=int(c-'a'+1);
	}
	while(i<=j)
	{
		if(s1[i]==s1[j])
		{
			if(s[i]>=s[j])
			{
				s[i]=s[i]-s[j];
				j--;
			}
			else
			{
				s[j]=s[j]-s[i];
				i++;
			}
		}
		else
		{
			if(s[i]>=s[j])
			{
				ans+=(s[j]);
				s[i]=s[i]-s[j];
				j--;
			}
			else
			{
				ans+=(s[i]);
				s[j]=s[j]-s[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}