#include<bits/stdc++.h>
using namespace std;
int a[200005],h[3005],l[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int g=1;g<=n;g++)
	{
		memset(l,0,sizeof(l));
		int s=0;
		for(int i=g;i<=n;i++)
		{
			int p=0;
			for(int j=1;j<=i;j++)
			{
				if(p==1)
				{
					l[j]=0;
					s--;
					break;
				}
				if(l[j]==a[i])
				{
					p=1;
					s--;
					l[j]=0;
				}
			}
			l[++s]=a[i];
		}
		for(int i=1;i<=m;i++) h[l[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<h[i]<<" ";
	return 0;
}
