#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
int main(){
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
		for(int e=1;e<=n;e++)
		{
			c[e]=0;
		}
		int cnt=1;
		for(int j=i;j<=n;j++)
		{
			int s=-1;
			for(int k=1;k<cnt;k++)
			{
				if(c[k]==a[j])
				{
					s=k;
					break;
				}
			}
			if(s!=-1)
			{
				for(int q=s;q<cnt;q++)
				{
					c[q]=0;
					cnt--;
				}
			}
			c[cnt]=a[j];
			cnt++;
		}
		for(int o=1;o<cnt;o++)
		{
			b[c[o]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
