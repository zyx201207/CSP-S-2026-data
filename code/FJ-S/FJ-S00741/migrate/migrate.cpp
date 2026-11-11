#include<bits/stdc++.h>
using namespace std;
struct D
{
	int no,bs;
};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d,ans=0;
		cin>>n>>d;
		vector<long long>sz(n);
		for(int q=0;q<n;q++)
		{
			cin>>sz[q];
		}
		vector<vector<int>>bians(n);
		for(int q=0;q<n;q++)
		{
			for(int w=q+1;w<n;w++)
			{
				if(sz[w]-sz[q]<=d)
				{
					bians[q].push_back(w);
				}
			}
		}
		for(int q=0;q<n;q++)
		{
			for(int w=q+1;w<n;w++)
			{
				long long mbs=INT_MAX,ljs=0;
				queue<D>dl;
				dl.push(D{q,0});
				while(!dl.empty())
				{
					D tmp=dl.front();
					dl.pop();
					if(tmp.no==w)
					{
						if(mbs==tmp.bs)
						{
							ljs++;
						}
						if(mbs==INT_MAX)
						{
							mbs=tmp.bs;
						}
						if(mbs!=tmp.bs)
						{
							break;
						}
						continue;
					}
					for(int e=0;e<bians[tmp.no].size();e++)
					{
						dl.push(D{e,tmp.bs+1});
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
