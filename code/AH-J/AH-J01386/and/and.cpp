#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn,ans,anss;
int a[200005][35],sum[200005],er[200005],pd[200005],pass[200005];
void find(int x,int y)
{
	int k=y,j=0;
	while(k)
	{
		j++;
		if(k%2)
		{
			pd[j]++;
		}
		a[x][j]=k%2;
		k/=2;
	}
	maxn=max(maxn,j);
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		find(i,b);
//		cout<<b<<" ";
//		for(int j=1;j<=10;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<"\n";
	}
	er[1]=1;
	for(int i=2;i<=35;i++)
	{
		er[i]=er[i-1]*2;
	}
	int ind=0;
	for(int i=maxn;i>=1;i--)
	{
		if(pd[i]>=m)
		{
			anss=er[i];
			ind=i;
			break;
		}
	}
//	cout<<pd[3];
	for(int i=1;i<=n;i++)
	{
		if(a[i][ind])
		{
			pass[++ans]=i;
		}
	}
	for(int i=ind-1;i>=1;i--)
	{
		if(pd[i]>=m)
		{
			int cnt=0;
			for(int j=1;j<=ans;j++)
			{
				if(!pass[j])
				{
					continue;
				}
				if(a[pass[j]][i])
				{
					cnt++;
				}
			}
			if(cnt>=m)
			{
				for(int j=ans;j>=1;j--)
				{
					if(!a[pass[j]][i])
					{
						pass[j]=0;
					}
				}
				anss+=er[i];
			}
		}
	}
	cout<<anss<<"\n";
	return 0;
}
/*
2026/10/31 10:15
洛谷名 Officer(不常用)
QID feiguangou 
*/


