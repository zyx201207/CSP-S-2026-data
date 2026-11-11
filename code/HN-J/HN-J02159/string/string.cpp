#include <bits/stdc++.h>
using namespace std;
int a[200002];
string b,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long j,n,i,sum=0,k=0,f=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
	  cin>>a[i];
	  cin>>b[i];
	}
	for(i=0;i<n;i++)
	  for(j=0;j<a[i];j++)
	  {
	    s[f]=b[i];
	    f++;
	  }
	for(i=0;i<f/2;i++)
	  if(s[i]!=s[f-i])
	    sum++;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
