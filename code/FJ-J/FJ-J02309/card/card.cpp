#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005]={0},ans[500005]={0};
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	int nu;nu=n;
	for(int i=0;i<n;i++)cin>>a[i];
	while(n--)
	{
		int c;
		c=nu-n;
		int b[500005]={0};
		for(int i=c-1;i<nu;i++)
		{
			b[i]=a[i];
		}
		for(int i=c-1;i<nu;i++)
			for(int j=i+1;j<nu;j++)
			{
				if(b[i]==b[j])
				{
					for(int k=i;k<j;k++)
					{
						b[k]=0;
					}
				}
			}
		for(int i=c-1;i<nu;i++)
		{
			if(b[i]!=0)
			{
				ans[b[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
