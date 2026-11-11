#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10,M=2*N;

int c,n,m,d,q;

bool dx[100*N];

int p[100*N];

int k[10*N];

int t1[10*N];
int t2[100*N];

int h[100*N],ne[100*M],e[100*M],idx;

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

bool su[100*N];
int ans=0x3f;
int st,ed;
void dfs(int u,int v)
{
	if(u==ed)
	{
		ans=min(ans,v);
		return;
	}
	
	su[u]=1;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!su[j])
		{
			su[j]=1;
			dfs(j,v+t2[j]);
		}
	}
}

int main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	memset (h,-1,sizeof h);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		cin>>t1[i];
	}
		
	for(int i=1;i<=n;i++)
	{
		int kk;cin>>kk;
		int aa;
		for(int i=1;i<=kk;i++)
		{
			int a,t;cin>>a>>t;
			if(i==1)
			{
				for(;;)
				{
					if(dx[a+k[a]*N])
					{
						k[a]++;
					}
					else
					{
						dx[a+k[a]*N]=1;
						aa=a+k[a]*N;
						t2[aa]=t;
						break;
					}
				}
			} 
			else
			{
				for(;;)
				{
					if(dx[a+k[a]*N])
					{
						k[a]++;
					}
					else
					{
						dx[a+k[a]*N]=1;
						add(a+k[a]*N,aa);
						add(aa,a+k[a]*N);
						aa=a+k[a]*N;
						t2[aa]=t;
						break;
					}
				}
			}
		}		
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int i1=1;i1<=k[i];i1++)
		{
			for(int i2=i1+1;i2<=k[i];i2++)
			{
				add(i+i1*N,i+i2*N);
				add(i+i2*N,i+i1*N);
			}
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>st>>ed;
		
		ans=0x3f;
		
		dfs(st,t1[st]+t1[ed]);
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}
