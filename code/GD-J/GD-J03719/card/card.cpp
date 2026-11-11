#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int q[MAXN],a[MAXN],ans[MAXN],n,m,h=0;
bool visit[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		h=0;
		for(j=1;j<=n;j++)
			visit[j]=false;
		for(j=i;j<=n;j++)
		{
			if(visit[a[j]]==true)
			{
				int temp=h;
				for(int k=1;k<=temp;k++)
				{
					if(q[k]==a[j])
					{
						h=k;
						break;
					}
				}
			}
			else
			{
				q[++h]=a[j];
				visit[a[j]]=true;
			}
		}
		for(j=1;j<=h;j++)
			ans[q[j]]++;
	}
	for(i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
