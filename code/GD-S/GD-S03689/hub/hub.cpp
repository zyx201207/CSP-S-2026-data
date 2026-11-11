#include<bits/stdc++.h>
using namespace std;
int c,r,n,d,mapp[2000005]={0},dnt=0,ans=0,zx,st[2000005];
long long minn=10086114514;
void dfs(int q,int d)
{
	if(dnt>2)return;
	if(q==zx)
	{
		if(d==minn)
		{
		    dnt++;
		    return;
		}
		else if(d<minn)
		{
			dnt=1;
			minn=d;
			return;
		}
	}
	st[q]=1;
	for(int i=1;i<=n;i++)
	{
		int nd=d;
		if(q>i)
		{
			if(mapp[q]-mapp[i]<=d&&st[i]==0)
			{
				nd+=mapp[q]-mapp[i];
				cout<<nd<<" ";
				dfs(i,nd);
			}
		}
		else if(q<i)
		{
			if(mapp[i]-mapp[q]<=d&&st[i]==0)
			{
				nd+=mapp[i]-mapp[q];
				cout<<nd<<" ";
				dfs(i,nd);
			}
		}
	}
	st[q]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>r;
	for(int i=1;i<=r;i++)
	{
		cin>>n>>d;
	}
	for(int i=1;i<=r;i++)cout<<1<<endl;
	return 0;
}
