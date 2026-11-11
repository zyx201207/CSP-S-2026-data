#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=10005;
int c,n,m,d,q,w[INF],k[INF],a[INF][INF],t[INF][INF],bl[INF],x,y,top=0,ans[INF];
pair<int,int>z[INF][INF];
bool cmp(int a,int b)
{
	return a<b;
}
void kskbl(int sum,int nows,int vec,int sta)
{
	if(sta==-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(z[nows][i].first==1)
			{
				kskbl(sum+w[nows]+t[i][z[nows][i].second],nows,z[nows][i].second,i);
			}
		}
		return;
	}
	if(nows==y)
	{
		ans[++top]=sum+w[nows]+t[sta][vec];
		return;
	}
	for(int i=1;i<=k[sta];i++)
	{
		if(bl[a[sta][i]]!=1 && i!=vec)
		{
			bl[i]=1;
			kskbl(sum,a[sta][i],i,sta);
			bl[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(z[nows][i].first==1 && i!=sta)
		{
			z[nows][i].first==0;
			kskbl(sum+t[sta][z[nows][i].second]+t[sta][vec],nows,z[nows][i].second,i);
			z[nows][i].first==1;
		}
	}
	return;
}
int main()
{//3271
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			z[a[i][j]][i]={1,j};
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		memset(ans,0,sizeof(ans));
		top=0;
		bl[x]=1;
		kskbl(0,x,-1,-1);
		sort(ans+1,ans+top+1,cmp);
		cout<<ans[1]<<endl;
	}
	return 0;
}
