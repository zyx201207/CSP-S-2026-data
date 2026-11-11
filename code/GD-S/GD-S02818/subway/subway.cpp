#include<bits/stdc++.h>
using namespace std;
struct travel{
	int s,e;
}trip[100001];
int c,n,m,d,q,w[500005];
vector<int>train[505],st[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x*2;j++)
		{
			int l;
			scanf("%d",&l);
			train[i].push_back(l);
			if(j%2==1)st[l].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long ans=0;
		scanf("%d%d",&trip[i].s,&trip[i].e);
		ans+=w[trip[i].s]+w[trip[i].e];
		for(int j=0;j<train[st[trip[i].s][0]].size();j+=2)
		{
			if(train[st[trip[i].s][0]][j]==trip[i].s)
			{
				ans+=train[st[trip[i].s][0]][j+1];
				break;
			}
		}
		for(int j=0;j<train[st[trip[i].e][0]].size();j+=2)
		{
			if(train[st[trip[i].e][0]][j]==trip[i].e)
			{
				ans+=train[st[trip[i].e][0]][j+1];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
