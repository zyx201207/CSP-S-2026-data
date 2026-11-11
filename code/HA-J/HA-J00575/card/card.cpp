#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500050],b[300050],ans[300050]={0},c[300050];
int main()
{
	freopen("card.in","c",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int ii=1;ii<=n;ii++)
	{
		memset(b,0,sizeof(b));
		int q=ii-1;
		for(int i=ii;i<=n;i++)
		{
			q++;
			c[q]=a[i];
			if(b[a[i]]==0)
				b[a[i]]=q;
			else
			{
				for(int j=b[a[i]]+1;j<q;j++)
					b[c[j]]=0;
				q=b[a[i]];
			}
		}
		for(int i=ii;i<=q;i++)
			ans[c[i]]++;
	}
	for(int i=1;i<m;i++)
		cout<<ans[i]<<" ";
	cout<<ans[m];
	return 0;
}
