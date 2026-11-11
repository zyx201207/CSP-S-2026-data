#include<bits/stdc++.h>
using namespace std;
long long s[200005];
char sc[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>sc[i];
	}
	int i=1;
	long long ls;
	long long ans=0;
	while(n>i)
	{
		ls=min(s[i],s[n]);
		if(sc[i]!=sc[n])
		{
			ans+=ls;
		}
		s[i]-=ls;
		s[n]-=ls;
		if(s[i]==0)
		{
			i++;
		}
		if(s[n]==0)
		{
			n--;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
