#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[10006],v[10006],minn=99999,d[10006],maxx=-1,s[10006],jg=9999;
bool b[10006][10006];
bool find(long long x)
{
	int kk=x;
	while(x!=s[kk])
	{
		kk--;
	}
	if(x==s[kk])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
long long dist(long long i,long long j)
{
	long long sum=0;
	minn=999;
	if(find(i)==1)
	{
		return 0;
	}
	else
	{
		for(int k=1;k<=n;k++)
		{
			if(k==j)
			{
				return 1;
			}
			else if(b[i][k]==1)
			{
				sum=1+dist(k,j);
				if(sum<minn)
				{
					minn=sum;
				}
			}
		}
		return minn;
	}
}
void jz(long long z,long long cs)
{
	if(z==k)
	{
		long long jl=0;
		maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(find(j)==1)
				{
					//cout<<s[i]<<" "<<s[j]<<" "<<endl;
					jl=dist(i,j);
					if(maxx<jl)
					{
						maxx=jl;
					}
				}
			}
		}
		if(maxx<jg)
		{
			jg=maxx;
		}
	}
	else
	{
		for(int i=cs+1;i<=n;i++)
		{
			s[z+1]=i;
			jz(z+1,i);
			s[z+1]=0;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
			b[u[i]][v[i]]=1;
		}
		jz(0,1);
		cout<<jg<<endl;
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
			for(int j=1;j<=n;j++)
			{
				b[i][j]=0;
			}
		}		
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
