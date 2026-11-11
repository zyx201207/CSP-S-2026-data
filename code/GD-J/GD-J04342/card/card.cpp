#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300003];
vector<int>b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		b.resize(1),b.push_back(a[i]);
		for(int j=i+1;j<=n;j++)
		{
			bool bz=1;
			for(int k=1;k<b.size();k++)
				if(a[j]==b[k])
				{
					bz=0,b.resize(k+1);
					break;
				}
			if(bz) b.push_back(a[j]);
		}
		for(int j=1;j<b.size();j++) cnt[b[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}
