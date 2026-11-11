#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char s[200005];
string ans1,ans2,ans0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++)
		{
			ans0+=s[i];
		}
	}
    if(ans0.size()%2==0)
    {
    	for(int i=0;i<ans0.size()/2;i++)
    	{
    		ans1+=ans0[i];
		}
		for(int i=ans0.size()/2;i<ans0.size();i++)
    	{
    		ans2+=ans0[i];
		}
	}
	else
	{
		for(int i=0;i<ans0.size()/2;i++)
    	{
    		ans1+=ans0[i];
		}
		for(int i=ans0.size()/2+1;i<ans0.size();i++)
    	{
    		ans2+=ans0[i];
		}
	}
	long long ans=0;
	for(int i=0;i<ans1.size();i++)
	{
		 if(ans1[i]!=ans2[i])
		 {
		 	ans++;
		 }
	} 
	cout<<ans;
	return 0;
} 
