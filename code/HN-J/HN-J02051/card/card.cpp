#include<bits/stdc++.h>
using namespace std;
int a[11000],b[11000],ans[11000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=0,hi;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=t;k>=1;k--)
				if(b[k]==a[j])
				{
					hi=0;
					for(int q=t;q>=k;q--)
					{
						b[q]=0;
						hi++;
					}
					t=t-hi;
					break;
				}
			t++;
			b[t]=a[j];
		}
		for(int j=1;j<=t;j++)
			ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}

