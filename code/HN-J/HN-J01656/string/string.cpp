#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n],ans=0,i,j;
	char b[n];
	string c="";
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(j=0;j<a[i];j++) c=c+b[i];
	} 
	for(i=0;i<c.size();i++)
	{
		if(c[i]!=c[c.size()-i-1])
		{
			c[i]=c[c.size()-i-1];
			ans++;
		 }
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
