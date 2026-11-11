#include<bits/stdc++.h>
using namespace std;
long long sum;
bool s[200005];
int maxn[200005],e[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]&a[j]>=maxn[2])
				{
					s[e[1]]=0;
					s[e[2]]=0;
					e[1]=i;
					e[2]=j;
					maxn[2]=a[i]&a[j];
					s[i]=1;
					s[j]=1;
					
				}
			}
		}
	if(m==3){
		for(int i=1;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					if(a[i]&a[j]>=maxn[2])
				{
					s[e[1]]=0;
					s[e[2]]=0;
					s[e[3]]=0;
					e[1]=i;
					e[2]=j;
					e[3]=z;
					maxn[3]=a[i]&a[j]&a[z];
					s[i]=1;
					s[j]=1;
					s[z]=1;
				}
				}
			}
		}
		
	}
	if(m!=2&&m!=3&&m==n)
	{
		maxn[m]==a[1]&a[2];
		for(int i=3;i<=m;i++)
		{
			maxn[m]&=a[i];
		}
	}
	cout<<maxn[m];
	return 0;
}
