#include <iostream>
#include <vector>

using namespace std;

long long n,m,a[1000010],able[1000010],ans;
vector<long long>t[60],id[60];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		able[i]=1;
		for(long long j=0;j<30;j++)
		{
			if((a[i]>>j)&1)t[j].push_back(a[i]),id[j].push_back(i);
		}
	}
	for(long long i=29;i>=0;i--)
	{
		if(t[i].size()>=m)
		{
			long long cnt=0;
			for(long long j=0;j<id[i].size();j++)cnt+=able[id[i][j]];
			if(cnt<m)goto out;
			ans|=(1<<i);
			for(long long j=0;j<id[i].size();j++)
			{
				if(able[id[i][j]])able[id[i][j]]++;
			}
			for(long long i=1;i<=n;i++)able[i]=max(0ll,able[i]-1);
		}
		out:;
	}
	cout<<ans;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
