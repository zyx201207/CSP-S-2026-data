#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx,d,cnt,mn=1<<60;
vector<long long> b[4000006];
struct node{
    long long a,b;
};
queue<node> q;
map<long long,long long> t[4000006];
void bfs(long long x)
{
    cnt=0;
    q.push({x,0});
	while(!q.empty())
	{
	    cnt++;
		long long xx=q.front().a,ii=lower_bound(a+1,a+n+1,a[xx])-a;
		if(q.front().b!=0)
        {
            t[ii][q.front().b]++;
        }
		for(int i=0;i<b[ii].size();i++)
		{
            if(b[ii][i])
            {
                q.push({b[ii][i],q.front().b+1});
                //cout<<b[ii][i]<<" "<<q.front().b+1<<" "<<ii<<" "<<x<<'\n';
            }
		}
		q.pop();
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int T,c;
	cin>>c>>T;
	while(T--)
	{
	    long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			int j=i+1;
			b[i].clear();
			while(a[i]+d>=a[j])
			{
				b[i].push_back(j);
				//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<"\n";
				j++;
				if(a[j]==0&&a[j+1]==0)
                {
                    break;
                }
			}
		}
		for(int i=1;i<=n;i++)
        {
            bfs(i);
            for(int j=i+1;j<=n;j++)
            {
                auto it=t[j].begin();
                //cout<<j<<" "<<it->first<<" "<<it->second<<"\n";
                if(it->second==2)
                {
                    ans++;
                }
                t[j].clear();
            }
        }
        cout<<ans<<'\n';
	}
}
