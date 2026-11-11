#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int ne,to,id;
}ed[500005];
int c,ha[500005],fl=1,n,m,d,q,w[600000],a[505][500005],t,k[505],be,en,sum,s;
priority_queue<int> l;
void bf()
{
	s=0;
	l.push(be);
	while(!l.empty())
	{
		int i=ha[l.top()];
		l.pop();
		for(;ed[i].ne!=0;i=ed[i].ne)
		{
			if(ed[i].to==en)
			{
				s++;
				return ;
			}
			else
			{
				l.push(ed[i].to);
				
			}
		}
		s++;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>t;
		for(int j=2;j<=k[i];j++)
		{
			cin>>a[i][j]>>t;
			ed[fl].id=i;
			ed[fl].ne=ha[a[i][j-1]];
			ed[fl].to=a[i][j];
			ha[a[i][j-1]]=fl;
			fl++;
			ed[fl].id=i;
			ed[fl].ne=ha[a[i][j]];
			ed[fl].to=a[i][j-1];
			ha[a[i][j]]=fl;
			fl++;
		}
	}
	while(q)
	{
		cin>>be>>en;
		sum+=w[be];
		sum+w[en];
		bf();
		sum+=t*s;
		cout<<sum<<endl;
		q--;
		sum=0;
	}
	return 0;	
}
