#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=2e6+10;
long long c,t,n,d,x[maxn],ca[maxn],r,ans,cnt,s;

struct p
{
	long long p,v;
}t1,f;

queue <p> q;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		memset(x,0,sizeof(x));
		memset(ca,0,sizeof(ca));
		cin>>n>>d;
		while(!q.empty())
			q.pop();
		for(int i=1;i<=n;i++)
			cin>>x[i];
		r=2;
		for(int i=1;i<=n;i++)
		{
			while(i<=r)
			{
				if(x[r]-x[i]<=d)
				{
					if(r<n)
						r++;
					else
					{
						ca[i]=r-i;
						break;
					}
				}
				else 
				{
					ca[i]=r-i-1;
					break;
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		cout<<ca[i]<<' ';
//		cout<<'\n';
		s=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				t1.p=i,t1.v=0,ans=1e18,cnt=0;
				q.push(t1);
				while(!q.empty())
				{
					f=q.front();
//					cout<<f.p<<' '<<f.v<<' '<<j<<'\n';
//					if(i==2&&j==5&&t==0)
//					cout<<f.p<<" "<<f.v<<' '<<i<<' '<<'\n';
					q.pop();
					if(f.p==j)
					{
						if(f.v<ans)
						{
							ans=f.v,cnt=1;
						}
						else if(f.v==ans)
							cnt++;
					}
					if(f.v>ans)
						continue;
					for(int k=1;k<=ca[f.p]&&f.p+k<=j;k++)
					{
						t1.p=f.p+k,t1.v=f.v+1;
						q.push(t1);
					}
				}
				if(cnt==2)
				{
					s++;
				}
//				cout<<ans<<' '<<cnt<<'\n';
			}
		}
		cout<<s<<'\n';
	}
	return 0;
} 
