#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b,d,e=0,g,i;
	long long m[200001],h=0;
	char o[200001];
	char c;
	cin>>n;
	for(b=1;b<=n;b++)
	{
		cin>>m[b]>>o[b];
	}
	for(g=1,i=n;g!=i&&g<i;)
	{
		if(o[g]!=o[i])
		{
			h=h+min(m[g],m[i]);
			if(m[g]<m[i])
			{
				m[i]-=m[g];
				g++;
			}
			if(m[g]>m[i])
			{
				m[g]-=m[i];
				i--;
			}
			if(m[g]==m[i])
			{
				g++;
				i--;
			}
		}
		else
		{
			if(m[g]<m[i])
			{
				m[i]-=m[g];
				g++;
			}
			if(m[g]>m[i])
			{
				m[g]-=m[i];
				i--;
			}
			if(m[g]==m[i])
			{
				g++;
				i--;
			}
		}
	}
	cout<<h;
	return 0;
}