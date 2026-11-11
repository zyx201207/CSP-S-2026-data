#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char b[200010];
long long ans=0;
int ser(int str,int las)
{
	if(str==las)
	{
		return 0;
	}
	else
	{
		if(b[str]!=b[las])
		{
			ans+=min(a[str],a[las]);
			if(a[str]>=a[las])
			{
				a[str]-=a[las];
				a[las]=0;
				ser(str,las-1);
			} 
			else
			{
				a[las]-=a[str];
				a[str]=0;
				ser(str+1,las);
			} 
		}
		else
		{
			if(a[str]>=a[las])
			{
				a[str]-=a[las];
				a[las]=0;
				ser(str,las-1);
			} 
			else
			{
				a[las]-=a[str];
				a[str]=0;
				ser(str+1,las);
			} 
		}
		return 0;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];	
	}
	ser(1,n);
	cout<<ans;
	return 0;
}


