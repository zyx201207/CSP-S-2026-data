#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005],e[300005],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int s=1;s<=n;s++)cin>>a[s],e[a[s]]=s;
	for(int s=1;s<=n;s++)b[s]=e[a[s]];
	for(int s=1;s<=n;s++)
	{
		for(int d=s;d<=n;d=b[d]+1)
		{
			c[a[d]]++;
		}
	}
	for(int s=1;s<=m;s++)printf("%d ",c[s]);
	return 0;
}
