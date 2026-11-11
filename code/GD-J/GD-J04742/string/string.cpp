#include<bits/stdc++.h>
using namespace std;
#define ll =2e14; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long a[ll],n,ans=0,p=0;string c[ll],s[ll];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		s[p++]=c[i];
	}
	for(int i=0;i<p/2;i++)
	{
	  if(s[i]!=s[p-i-1])ans++;
	}
	cout<<ans;
}

