#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>
const int N=0x3f3f3f3f;
int a[500005],b[500005],c[500005],dt[1005][1005],cpo,n,m,d,q;
ll dst[500005];
int op=0;
bool ml[500005];
vector<int> mp[500005];
void dfs2(int x)
{  
	priority_queue<pii,vector<pii>,greater<pii> > mh;
	mh.push(make_pair(0,x));
	while(!mh.empty())
	{
		int p=mh.top().second;
		ll dpt=mh.top().first;
		mh.pop();
		if(dpt>dst[p])
			continue;
		for(int i=0;i<mp[p].size();i++)
		{
			int to=mp[p][i];
			if(dst[to]<=dpt+dt[p][to])
				continue;
			dst[to]=dpt+dt[p][to];
			mh.push(make_pair(dst[to],to));
		}
	}
	for(int i=1;i<=m;i++)
		dt[x][i]=dst[i];
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cpo>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			dt[i][j]=N;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
//	if(cpo>=12&&cpo<=19)
//	{   int gj=0;
//		for(int i=1;i<=n;i++)
//		{
//			int k;
//			cin>>k;
//			for(int j=1;j<=k;j++)
//			{
//				int ca,t;
//				cin>>ca>>t;
//				b[j]=ca;
//				ad=t;
//			}
//			for(int j=1;j<k;j++)
//			{
//				for(int l=j+1;l<=k;l++)
//				{
//					mp[b[l]].push_back(b[j]);
//					mp[b[j]].push_back(b[j]);
//				}
//			}
//		}
//		
//		return 0;
//	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int ca,t;
			scanf("%d%d",&ca,&t);
			b[j]=ca;
			c[ca]=t;
		}
		for(int j=1;j<k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				dt[b[l]][b[j]]=min(c[b[l]]+c[b[j]],dt[b[l]][b[j]]);
				dt[b[j]][b[l]]=dt[b[l]][b[j]];
				mp[b[l]].push_back(b[j]);
				mp[b[j]].push_back(b[j]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		memset(dst,0x3f,sizeof(dst));
		dst[i]=0;
		dfs2(i);
	}
	while(q--)
	{
		int vaa,vbb;
		cin>>vaa>>vbb;
		ll ansn=min(dt[vaa][vbb],dt[vbb][vaa])+a[vaa]+a[vbb];
		printf("%lld\n",ansn);
	}
	return 0;
} 
