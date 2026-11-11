#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
int n,m,cnt;
int a[N],xl[N],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i]<a[i-1])flag=false;
	}
	if(flag)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(a[i+1]!=a[i])ans[a[i]]=cnt;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int num=0;
		for(int j=i;j<=n;j++)
		{
			xl[++num]=a[j];
			int k=num-1;
			while(k>0&&xl[num]!=xl[k])
			{
				k--;
			}
			if(k>0)
			{
				num=k;
				xl[num]=a[j];
			}
		}
		for(int j=1;j<=num;j++)
		{
			ans[xl[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

