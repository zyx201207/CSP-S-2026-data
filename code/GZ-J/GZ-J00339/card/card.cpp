//GZ-J00339 贵阳市南明区华麟学校 孙君瑞
#include<bits/stdc++.h>
using namespace std;
int n,m,tmp,a[300005],b[300005],cnt[200005];
bool flag[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		tmp=0;
		for(int j=n;j>=i;j--)
		{
			for(int k=i;k<=j;k++)
			{
				if(b[k]==a[j])
				{
					tmp=j-1;
				}
			}
			b[++tmp]=a[j];
		}
		for(int j=1;j<=tmp;j++)
		{
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
