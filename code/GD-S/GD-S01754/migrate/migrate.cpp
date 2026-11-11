#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],di[2000005],cs[2000005],num;
vector<long long> v[2000005];
struct node{
	long long dis,jb;
	bool operator<(const node& x) const
	{
		return dis>x.dis;
	}
};
priority_queue<node> q;
node q1,q2;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0)
	{
		t--;
		cin>>n>>d;
		num=0;
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			v[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i!=j&&abs(a[i]-a[j])<=d)
				{
					v[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			fill(di+1,di+1+n,5000000);
			fill(cs+1,cs+1+n,0);
			di[i]=0;
			q1.dis=0;
			q1.jb=i;
			q.push(q1);
			while(!q.empty())
			{
				q1=q.top();
				q.pop();
				if(q1.dis>di[q1.jb])
				{
					continue;
				}
				if(q1.jb==n)
				{
					break;
				}
				for(int j=0;j<v[q1.jb].size();j++)
				{
					q2.jb=v[q1.jb][j];
					q2.dis=q1.dis+1;
				//	cout<<q2.jb<<endl;
					if(q2.dis<di[q2.jb])
					{
						di[q2.jb]=q2.dis;
					//	cout<<q2.jb<<": "<<di[q2.jb]<<endl;
						cs[q2.jb]=1;
						q.push(q2);
					}
					else if(q2.dis==di[q2.jb])
					{
						cs[q2.jb]++;
						q.push(q2);
					}
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				if(cs[j]==2)
				{
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
