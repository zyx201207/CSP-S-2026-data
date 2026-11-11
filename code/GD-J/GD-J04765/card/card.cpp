#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long n,m;
bool spA=true;
vector<long long> a(N,0),ans(M,0),ed(M,0),cntl(M,0),cntr(M,0);
vector<bool> vis(M,false);
deque<long long> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ed[a[i]]=i;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1]) spA=false;
	}
	//cout<<spA<<"\n";
	if(spA) spA=true;
	if(spA)
	{
		for(int i=1;i<=n;i++) cntl[a[i]]++;
		int sum=0;
		//for(int i=1;i<=m;i++) cout<<cntl[i]<<"\n";
		for(int i=1;i<=m;i++)
		{
			sum+=cntl[i];
			cout<<sum<<" ";
		}
		return 0;
	}
	//for(long long i=1;i<=n;i++) cntl[a[i]]++;
	for(int i=1;i<=n;i++) 
	{
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]]) vis[a[j]]=true;
			else
			{
				while(!q.empty()&&q.back()!=a[j])
				{
					vis[q.back()]=false;
					q.pop_back();
				}
				q.pop_back();
			}
			q.push_back(a[j]);
		}
		while(!q.empty())
		{
			ans[q.front()]++,vis[q.front()]=false;
			q.pop_front();
		}
	}
	for(long long i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
