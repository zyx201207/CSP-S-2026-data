#include<bits/stdc++.h>
using namespace std;
int n;
long long a,ans=0;
string s;
char b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		for(int j=ans;j<ans+a;j++)
		{
			s[j]=b;
		}
		ans=ans+a;
	}
	int su=(ans+1)/2,z=0;
	for(int i=su;i<ans;i++)
	{
		if(s[i]!=s[ans-i-1])
		{
			z++;
		}
	}
	cout<<z;
	return 0;
}
