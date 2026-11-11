#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[500000],c[300005],p[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
			if(p[b[j]]!=0)
			{
				for(int z=p[b[j]];z<=j-1;z++)
				{
					p[b[z]]=0;
					b[z]=0;
				}
				p[b[j]]=j;
			}
			else p[b[j]]=j;
			if(j==n)
			{
				for(int z=1;z<=n;z++)
				if(b[z]!=0)
				{
					c[b[z]]++;
					p[b[z]]=0;
					b[z]=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	cout<<c[i]<<" ";
	return 0;
}