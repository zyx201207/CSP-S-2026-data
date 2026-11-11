#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
const int N1=5e6+10;
int a[N];
int w[N1];
int num[N1];
int y[N];
int main()
{
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int o=1;
		for(int j=i;j<=n;j++)
		{
			if(w[a[j]]==0||o<w[a[j]])
			{
				w[num[o]]=0;
				num[o]=a[j];
				w[a[j]]=o;
				o++;
			}
			else
			{
				o=w[a[j]];
				num[o]=a[j];
				w[a[j]]=o;
				o++;
			}
		}
		for(int j=1;j<=o-1;j++)
		{
			y[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<y[i]<<" ";
	}
	return 0;
}