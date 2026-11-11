#include<bits/stdc++.h>
using namespace std;
int const N=1e6;
int n,m,s[N];
int r[N];
int c[N];
vector<int> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			v.push_back(s[i]);
			if(r[s[i]]!=0)
				v.erase(v.begin()+r[s[i]]-i+1,v.begin()+r[s[i]]);
			r[s[i]]=j;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("0");
	}
	return 0;
}
