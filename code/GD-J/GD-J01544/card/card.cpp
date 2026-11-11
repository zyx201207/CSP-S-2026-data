#include<bits/stdc++.h>
using namespace std;	
int n,m;
int a[500005];
int ans[300005];
void ca(int s)
{
	int f[500005];
	int l[500005];
	int no = 1;
	for(int i=s;i<=n;i++)
	{
		if(f[a[i]]!=0)
		{
			for(int j=f[a[i]]+1;j<=i;j++)
			{
				l[j] = 0;
				f[l[i]] = 0;
			}
			no = f[a[i]];
		}else{
			l[no] = a[i];
			f[a[i]] = no;
		}
		no++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]!=0)
		{
			ans[i]++;
		}
	}
	return ;
 } 
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
		ca(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
 } 
