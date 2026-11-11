#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],b[N],f[N],d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	d=n;
	int k=0;
	while(d!=0)
	{
		int c=0;
		for(int i=n-d+1;i<=n;i++)
		{
			c++;
			b[c]=a[i];
			for(int j=1;j<=c-1;j++)
			{
				if(b[j]==b[c])
				{
					k+=j;
					for(int g=k;g<c;g++)
					{
						b[j]=0;
					}
				}
			}
			k=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=0)
			{
				f[b[i]]++;
			}
		}
		d--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
