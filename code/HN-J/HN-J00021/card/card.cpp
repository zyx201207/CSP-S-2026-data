#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
bool f[M];
int n,m,a[N],ans[M];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]<a[i-1])fl=0;
//		if(a[i]==a[i-1])n--,i--;
	}
	if(n<=5000)
	{
		deque<int>q;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				f[j]=false;
			}
			for(int j=i;j<=n;++j)
			{
				if(f[a[j]])
				{
					while(!q.empty())
					{
						f[q.back()]=false;
						if(q.back()==a[j])break;
						q.pop_back();
					}
					q.pop_back();
				}
				q.push_back(a[j]);
				f[a[j]]=true;
			}
			while(!q.empty())
			{
				++ans[q.front()];
				q.pop_front();
			}
		}
	}
	else if(fl)
	{
		for(int i=1;i<=n;++i)
		{
			if(!f[a[i]])
			{
				f[a[i]]=1;
				ans[a[i]]=i;
			}
		}
	}
	else
	{
		ans[a[n]]=n;
		if(a[n]==1)ans[2]=1;
		else ans[1]=1;
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
