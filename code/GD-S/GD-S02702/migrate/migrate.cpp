#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
int c,t,n;
ll d;
ll x[2000005];
bool vis[2000005];
int main()
{
//	freopen("migrate2.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12)//A,8pts
		{
			ll k=x[2]-x[1];
			if(d<2*k||d>=k*n)cout<<"0\n";
			else cout<<n-(d/k*2-1)<<"\n";
		}
		else if(c==13||c==14)//B?
		{
			cout<<"0\n";
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int cnt=0;
					for(int msk=0;msk<(1<<n);msk++)
					{
						fill(vis+1,vis+1+n,0);
						vector<int> v;
						v.push_back(i);
						int cnt=__builtin_popcount(msk);
						int tmp=msk,id=1;
						while(tmp)
						{
							if(tmp&1&&id!=i&&id!=j)v.push_back(id);
							id++,tmp>>=1;
						}
						v.push_back(j);
						bool flag=0;
						for(int k=0;k<v.size()-1;k++)
						{
							if(v[k]<=i||v[k]>=j)continue;
							if(x[v[k]]-x[v[k-1]]>d)
							{
								flag=1;
								continue;
							}
						}
						if(!flag)cnt++;
					}
					if(cnt==2)ans++;
				}
			}	
			cout<<ans<<"\n";	
		}
	}
	return 0;
}
//maybe 8pts
