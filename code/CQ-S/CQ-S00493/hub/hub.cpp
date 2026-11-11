#include <bits/stdc++.h>
using namespace std;

int n,K;

const int M=4e3+5;
const int N=1e5+5;
vector<int>v[M];
pair<int,int>sx[M];
int ru[M];

int deep[M][2];

void find(int x, int fa, int bad, int op)
{
	deep[x][op]=deep[fa][op]+1;
	for (int i=0; i<v[x].size(); i++)
	{
		int y=v[x][i];
		if (y==fa or y==bad) continue;
		find(y,x,bad,op);
	}
}

int maxdeep[M];

int dfs(int x, int fa, int bad, int mid)
{
	maxdeep[x]=0;
	int cnt=0;
	for (int i=0; i<v[x].size(); i++)
	{
		int y=v[x][i];
		if (y==fa or y==bad) continue;
		cnt+=dfs(y,x,bad,mid);
		maxdeep[x]=max(maxdeep[x],maxdeep[y]+1);
	}
	if (maxdeep[x]>=mid) cnt++;
	return cnt;
}

int bfs(int x, int bad, int mid)
{
	deep[0][0]=deep[0][1]=-1;
	for (int i=1; i<=n; i++) deep[i][0]=deep[i][1]=0;
	find(x,0,bad,0);
	int t=x,maxn=0;
	for (int i=1; i<=n; i++)
	{
		if (deep[i][0]>maxn)
		{
			maxn=deep[i][0];
			t=i;
		}
	}
	int S=t;
	find(S,0,bad,0);
	t=x,maxn=0;
	for (int i=1; i<=n; i++)
	{
		if (deep[i][0]>maxn)
		{
			maxn=deep[i][0];
			t=i;
		}
	}
	int T=t;
	find(T,0,bad,1);
	int cnt=0;
//	for (int i=1; i<=n; i++)
//	{
//		cout<<deep[i][0]<<","<<deep[i][1]<<"}";
//	}
//	cout<<" "<<maxn<<"\n";
	for (int x=1; x<=n; x++)
	{
		if (deep[x][0]+deep[x][1]==maxn)
		{
			if (min(deep[x][0],deep[x][1])>=mid)
			{
				cnt++;
				for (int i=0; i<v[x].size(); i++)
				{
					int y=v[x][i];
					if (deep[y][0]+deep[y][1]==maxn or y==bad) continue;
					cnt+=dfs(y,x,bad,mid);
				}
			}
		}
	}
//	cout<<x<<" "<<bad<<":"<<S<<","<<T<<":"<<cnt<<"\n";
	return max(cnt,1);
}

int check(int x)
{
	int res=bfs(1,0,x);
	for (int i=1; i<n; i++)
	{
		int l=sx[i].first,r=sx[i].second;
		ru[l]--,ru[r]--;
		res=min(res,bfs(l,r,x)+bfs(r,l,x));
		ru[l]++,ru[r]++;
	}
//	cout<<x<<":"<<res<<"\n";
	return (res<=K);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int Testnum,T;
	cin>>Testnum>>T;
	while (T--)
	{
		cin>>n>>K;
		for (int i=1; i<=n; i++)
		{
			v[i].clear();
			ru[i]=0;
		}
		
		for (int i=1; i<n; i++)
		{
			int l,r;
			cin>>l>>r;
			v[l].push_back(r);
			v[r].push_back(l);
			ru[l]++,ru[r]++;
			sx[i]={l,r};
		}
		int l=0,r=n;
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}

