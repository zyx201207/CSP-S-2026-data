#include<bits/stdc++.h>
using namespace std;
map<int,int> sheng;//剩下的
map<int,int> dq;//当前有的
int s[200010];
int n,m;
int a[200010]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)//留下来的个数+1 
	{
		dq.clear();
		for(int i=l-1;i<=n;i++)
		{
			s[i]=0;
		}
		for(int i=l;i<=n;i++)//开始模拟 
		{
			if(a[dq[a[i]]]==a[i])
			{
				for(int j=dq[a[i]];j<i;j++)
				{
					s[j]=1;
					dq[a[j]]=0;
				}
			}
			dq[a[i]]=i;
		}
		for(int i=l;i<=n;i++)//开始模拟 
		{ 
			if(s[i]==0)
			{
				sheng[a[i]]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sheng[i]<<" ";
	}
	return 0;
}
