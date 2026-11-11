#include<bits/stdc++.h>
using namespace std;
int book2[300006],a[500006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int book1[300006]={0},b[500006]={0};
		int tot=1;
		for(int j=i;j<=n;j++)
		{
			b[tot]=a[j];
			book1[a[j]]++;
			if(book1[a[j]]==2)
			{
				b[tot]=0;
				tot--;
				book1[b[tot]]--;
				while(b[tot]!=a[j])
				{
					b[tot]=0;
					tot--;
					book1[b[tot]]--;
				}
			}
			tot++;
		}
		for(int j=1;j<=m;j++)
		{
			if(book1[j]!=0) book2[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<book2[i]<<" ";
	}
	return 0;
}
