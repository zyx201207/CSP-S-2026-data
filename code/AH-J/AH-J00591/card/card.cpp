#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],b[N];
bool f[M];
int s[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[j]=j-1;
		}
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
			}
			else
			{
				int p=j;
				for(int k=b[j];a[k]!=a[j];k=b[k])
				{
					f[a[k]]=0;
					p=k;
				}
				b[j]=b[p];
			}
		}
		for(int j=1;j<=m;j++)
		{
			s[j]+=(f[j]?1:0);
		}
		memset(f,0,sizeof f);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' ';
	}
}
