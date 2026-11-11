#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q1,st[N],z,s,minn[N];
bool b[N];
int q[N];
vector< int > e1[N],e2[N];
void dij()
{
	q[1]=s;
	int t=0,h=1;
	while(t<h)
	{
		t++;
		int len=e1[q[t]].size(),mi=INT_MAX,vm=0,h1=h;
		for(int i=0;i<len;i++)
		{
			int  v=e1[q[t]][i],w=e2[q[t]][i];
			minn[v]=min(minn[v],minn[q[t]]+w);
			if(minn[v]<mi&&!b[v])
			{
				mi=minn[v];
				vm=v;
			}
			if(!b[v])
			{
				h++;
			    q[h]=v;
			    b[v]=1;
			}
	}
}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)
		cin>>st[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a[k+1],t[k+1];
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int l=1;l<=k;l++)
			for(int j=l+1;j<=k;j++)
			{
				e1[a[l]].push_back(a[j]);
				e1[a[j]].push_back(a[l]);
				e2[a[l]].push_back(t[l]+t[j]);
				e2[a[j]].push_back(t[l]+t[j]);
			}
	}
	while(q1--)
	{
		memset(minn,0x3f3f3f3f,sizeof(minn));
		memset(b,0,sizeof(0));
		cin>>s>>z;
		minn[s]=0;
		b[s]=1;
		dij();
		cout<<minn[z]+st[s]+st[z]<<endl;
	}
	return 0;
}
