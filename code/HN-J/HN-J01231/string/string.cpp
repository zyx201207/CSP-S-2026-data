#include <bits/stdc++.h>
using namespace std;
string c,wyq;
long long a,n,l,cs;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	wyq+='q';
	for (long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		l+=a;
		for (long long j=1;j<=a;j++)
		{
			wyq+=c;
		}
	}
	for (long long i=1;i<=l;i++)
	{
		if (wyq[i]!=wyq[l-i+1])
		{
			cs++;
		}
	}
	cout<<cs/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
