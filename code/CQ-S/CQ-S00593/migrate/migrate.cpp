#include<bits/stdc++.h>
using namespace std;

int n,d;
int t,s;
int path[3][20005];
int a[20005];

int find(int u)
{
	int w=0;
	while(u+d<t)
	{
		int l=u,r=t,mid,res=-1;
		while(l<r)
		{
			mid=(l+r)/2;
			if(a[mid]-a[u]>=d) r=mid-1;
			else l=mid+1,res=mid;
		}
		u=res;
		w++;
		path[1][w]=res;
	}
	w++;
	return w;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		if(n>20005) break;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=i,t=j;
				int res=find(i);
				for(int k=1;k<=res;k++) path[2][k]=path[1][k];
				s=j,t=i;
				int res2=find(j); 
				if(res2!=res) continue;
				bool f=1;
				for(int k=1;k<=res;k++) 
				{
					if(path[2][k]!=path[1][res-k+1])
					{
						f=0;
						break; 
					}
				} 
				if(f) ans++;
			}
		}
		cout<<ans;
	}
	
	
	return 0;
}

