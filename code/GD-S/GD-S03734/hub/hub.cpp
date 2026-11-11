#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k;
int a[15],b[15],minn,w[15]; 
vector<int> v[N];
void check(int x,int fa)
{
	for(register int i=0;i<v[x].size();++i)
	{
		int to=v[x][i];
		if(to==fa) continue;
		if(a[to]==1) b[to]=1,check(to,x);
	}
}
void dfs(int x,int fa,int dep)
{
	if(a[x]==0) w[x]=min(w[x],dep);
	for(register int i=0;i<v[x].size();++i)
	{
		int to=v[x][i];
		if(to==fa) continue;
		dfs(to,x,dep+1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(register int i=1;i<=n;++i) v[i].clear();
		for(register int i=1;i<n;++i)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y),v[y].push_back(x);
		}
		minn=1e9+5;
		for(register int i=1;i<pow(2,n);++i)
		{
			for(register int i=1;i<=n;++i) w[i]=1e9+5,a[i]=0,b[i]=0;
			int t=0,x=i,I=1,maxx=0;
			while(x>0) t+=(x&1),a[I]=(x&1),x>>=1,I++;
			if(t!=k) continue;
			t=0;
			for(register int i=1;i<=n;++i)
				if(a[i]==1&&b[i]==0) t++,check(i,0);
			if(t>2) continue;
			for(register int i=1;i<=n;++i)
			{
				if(a[i]==0) continue;
				dfs(i,0,0);
			}
			for(register int i=1;i<=n;++i)	
				if(a[i]==0) maxx=max(maxx,w[i]);
			minn=min(minn,maxx);
		}
		cout<<minn<<endl; 
	}
	return 0;
}
