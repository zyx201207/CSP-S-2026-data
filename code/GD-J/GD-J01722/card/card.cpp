#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[200005],d[500005],t,last[200005],k;
void part1()
{
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=i;j<=n;j++)
		{
			d[++t]=a[j];
			while(t>last[a[j]])
			{
				t--;
				last[d[t]]=INT_MAX;
			}
			last[a[j]]=t;
		}
		for(int j=1;j<=t;j++)
		{
			ans[d[j]]++;
			last[d[j]]=INT_MAX;
		}
	}
	return;
}
void part2()
{
	for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) ans[a[i]]=i;
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[i]=INT_MAX;
		if(a[i]<a[i-1]) k=1;
	}
	if(k) part1();
	else part2();
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
