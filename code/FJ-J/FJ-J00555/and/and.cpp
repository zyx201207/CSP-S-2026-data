#include<bits/stdc++.h>
#define x first 
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10,M=31;
int n,m;
int a[N],sum[M],res[N];
int sum1[N],sum2[N];
int fact[M],f[50][50];
bool st[N],A=1,ff=1;
priority_queue<PII> q;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fact[0]=1;
	for(int i=1;i<M;i++)
	{
		fact[i]=fact[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bool f=0;
		for(int j=0;j<30;j++)
		{
			if(a[i]>>j&1)
			{
				res[i]++;
				sum[j]++;
			}
			if(a[i]==fact[i]-1)
			{
				f=1;
			}
		}
		if(!f)
		{
			A=0;
		}
		if(a[i]>=4)
		{
			ff=0;
		}
		q.push({res[i],a[i]});
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][1]=a[i];
			for(int j=1;j<=min(i,m);j++)
			{
				for(int k=1;k<i;k++)
				{
					f[i][j]=max(f[i][j],f[k][j-1]&a[i]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,f[i][m]);
		}
		cout<<ans<<endl;
		return 0;
	}
	bool flag=0;
	for(int i=0;i<=30;i++)
	{
		if(sum[i]>=m)
		{
			flag=1;
			break;
		}
	}
	if(n<=2000&&m==2)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(m==n-1)
	{
		sum1[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			sum1[i]=sum1[i-1]&a[i];
		}
		sum2[n]=a[n];
		for(int i=n-1;i>=1;i--)
		{
			sum2[i]=sum2[i+1]&a[i];
		}
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,sum1[i-1]&sum2[i+1]);
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(A)
	{
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(ff)
	{
		int x=0,y=0,k=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				x++;
			}
			if(a[i]==2)
			{
				y++;
			}
			if(a[i]==3)
			{
				k++;
			}
		}
		if(k>=2||x>=2&&y>=2)
		{
			cout<<3<<endl;
		}
		else
		{
			if(y>=2)
			{
				cout<<2<<endl;
				return 0;
			}
			if(k&&y)
			{
				cout<<2<<endl;
				return 0;
			}
			else
			{
				if(k&&x)
				{
					cout<<1<<endl;
					return 0;
				}
				else
				{
					if(x&&y)
					{
						cout<<1<<endl;
						return 0;
					}
					else
					{
						cout<<0<<endl;	
						return 0;
					}	
				}
			}
		}
	}
	if(!flag||m<=1)
	{
		cout<<0<<endl;
		return 0;
	}
	int id=0;
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		a[++id]=t.y;
	}
	int now=m;
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		vector<int> vec;
		if(sum[i]>=m)
		{
			int k=0;
			for(int j=1;j<=n;j++)
			{
				if(k>=m)
				{
					break;
				}
				if(a[j]>>i&1)
				{
					k++;
					if(!st[j])
					{
						vec.push_back(j);
						cnt++;
					}
				}
			}
		}
		if(now>=cnt)
		{
			now-=cnt;
			for(int j=0;j<vec.size();j++)
			{
				int k=vec[j];
				st[k]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(st[i])
		{
			if(!ans)
			{
				ans=a[i];
			}
			else
			{
				ans=ans&a[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;	
} 

