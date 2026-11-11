#include<bits/stdc++.h>
using namespace std;
int b[500001],s[300001],e[300001],n,m;
void u(int i)
{
	int d=b[i];
	s[d]++;
	if(e[b[i]]!=n) u(e[b[i]]+1);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		e[b[i]]=i;
	}
	for(int i=1;i<=n;i++) u(i);
	for(int i=1;i<=m;i++)
	{
		printf("%d ",s[i]);
	}
	return 0;
}
