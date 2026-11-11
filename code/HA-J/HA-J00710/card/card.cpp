#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans[300010],a[500010],memory[300010];
bool b[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(int i=n-1;i>=0;i--)
	{
		if(b[a[i]]==true)
		{
			for(int j=memory[a[i]]-1;j>a[i];j--)
				b[a[j]]==false;
			memory[a[i]]=i;
		}
		else
		{
			b[a[i]]=true;
			memory[a[i]]=i;
		}
		for(int j=n-1;j>=i;j--)
			if(b[a[j]]==true)
				ans[a[j]]++;
	}
	if(m==1)
	{
		printf("%d",n);
		return 0;
	}
	for(int i=0;i<m;i++)
		printf("%d ",ans);
	return 0;
}
