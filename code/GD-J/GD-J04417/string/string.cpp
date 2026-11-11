#include<bits/stdc++.h>
char s[5000000010],c[5000000010];
long long ans=0,num=0,abc=0;
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		ans+=a;
		for(int j=num;j<ans;j++){
			s[j]=b;
		}
		num+=a;
	}
	for(int i=ans;i>=0;i--)
	{
		c[ans-i]=s[i];
	}
	for(int i=1;i<=ans/2;i++)
	{
		if(c[i]!=c[ans-i+1])
		{
			abc++;
		}
	}
	cout<<abc;
}
