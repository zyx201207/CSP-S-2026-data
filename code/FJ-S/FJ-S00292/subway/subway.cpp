#include<bits/stdc++.h>
using namespace std;
long long www[500001];
int head[500001],ne[20000001],to[20000001],v[500001];
long long w[20000001],cnt=1;
long long x[500001],y[500001],an[500001],vv;
priority_queue<pair<long long,int> >qq;
void ed(long long u,long long v,long long ww)
{
	to[cnt]=v;
	ne[cnt]=head[u];
	w[cnt]=ww;
	head[u]=cnt++;
}
void solve()
{
	while(!qq.empty())
	{
		int xx=qq.top().second;
		if(xx==vv)
		{
			break;
		}
		long long yy=-qq.top().first;
		qq.pop();
		for(int i=head[xx];i;i=ne[i])
		{
			if(v[to[i]]==0)
			{
				an[to[i]]=yy+w[i];
				v[to[i]]=1;
				qq.push({-an[to[i]],to[i]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
   long long c,m,i,j,n,d,q,k,l;
   cin>>c>>n>>m>>d>>q;
   for(i=1;i<=m;i++)
   {
   	cin>>www[i];
   }
   for(i=1;i<=n;i++)
   {
   	   cin>>k;
   	   for(j=1;j<=k;j++)
   	   {
   	   	cin>>x[j]>>y[j];
	   }
	   for(j=1;j<=k;j++)
	   {
	   	for(l=j+1;l<=k;l++)
	   	   {
	   		ed(x[j],x[l],y[j]+y[l]);
	   		ed(x[l],x[j],y[j]+y[l]);
		   }
	   }
   }
   while(q--)
   {
   	 long long uu,ans=0;
   	 for(i=1;i<=m;i++)
   	 {
   	 	v[i]=0;
	 }
   	 cin>>uu>>vv;
   	 an[uu]=0;
   	 ans=www[uu]+www[vv];
   	 while(!qq.empty())
   	 {
   	 	int xx=qq.top().second;
   	 	v[xx]=0;
   	 	qq.pop();
	 }
	 qq.push({0,uu});
	 solve();
	 ans+=an[vv];
	 cout<<ans<<endl;
   }
	return 0;
}

