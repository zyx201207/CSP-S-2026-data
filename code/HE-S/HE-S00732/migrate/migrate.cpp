#include <bits/stdc++.h>
using namespace std;
int c,t,x[2000005],a[2000005],d,minn,xans;
void find(int x,int f,int b)
{
	if(x==f)
	{
		minn=min(minn,b);
		return;
	}
	for(int i=1;i<=d;i++)
	{
		if(a[i]&&x+i<=f)
		{
			find(x+i,f,b+1);
		}
	}
}
void dfs(int x,int f,int b)
{
	if(x==f)
	{
		if(b==minn) xans++;
		return;
	}
	for(int i=1;i<=d;i++)
	{
		if(a[i]&&x+i<=f)
		{
			dfs(x+i,f,b+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		minn=1e9,xans=0;
		int n,ans=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			a[x[i]]=i;
		}
		for(int l=0;l<n-2;l++)
		{
			for(int r=l+2;r<n;r++)
			{
				minn=1e9,xans=0;
				find(l,r,0);
				dfs(l,r,0);
				if(xans==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
// 观鸟入小P
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

// 你这个鸟能教我攀爬、Dash、果冻跳、蹬墙跳、Super、Hyper和凌波微步吗 (凭什么第九章有15个心的门啊，我不想找心啊) 
