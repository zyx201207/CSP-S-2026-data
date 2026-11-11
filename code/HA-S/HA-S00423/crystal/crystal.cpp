#include<bits/stdc++.h>
using namespace std;

struct node
{
	int majiku;
}cry[500005];

int cmp(node p,node q)
{
	if(p.majiku<q.majiku)
	{
		return 1;
	}
	if(p.majiku>q.majiku)
	{
		return 0;
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int mint=0;
	for(int rinji=1;rinji<=n;rinji++)
	{
		cin>>cry[rinji].majiku;
		if(cry[rinji].majiku<0)
		{
			cry[rinji].majiku=-cry[rinji].majiku;
		}
	}
	sort(cry+1,cry+1+n,cmp);
	for(int rinji=1;rinji<=n;rinji++)
	{
		if(cry[rinji].majiku!=cry[rinji+1].majiku)
		{
		mint=cry[rinji+1].majiku-cry[rinji].majiku;
		m=m-mint;
		cry[rinji].majiku=cry[rinji+1].majiku;
		if(m<=0)
			{
			break;
			}
		sum++;
		}
	}
	cout<<sum;
	return 0;
}
