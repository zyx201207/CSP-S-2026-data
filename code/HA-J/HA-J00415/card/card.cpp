#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f[300005];
int fs[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(fs,0,sizeof(fs));
		int s[500005]={0};
		int t=1;
		for(int j=i;j<=n;j++)
		{
			s[t]=a[j];
			fs[s[t]]++;
			bool check=0;
			for(int k=1;k<t;k++)
			{
				if(s[k]==s[t])
				{
					for(int l=k;l<=t;l++)
					{
						fs[s[l]]--;
						s[l]=0;
					}
					t=k;
				}
			}
			if(fs[a[j]]==0)
			{
				s[t]=a[j];
				fs[a[j]]++;
				t++;
			}
			if(!check)
			{
				t++;
			}
		}
		sort(s+1,s+t+1);
		s[0]=-1000;
		for(int j=1;j<=t;j++)
		{
			if(s[j]==s[j-1])
			{
				continue;
			}
			else{
				f[s[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
}

