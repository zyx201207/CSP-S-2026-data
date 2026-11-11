#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int M=5e5+1;
int n,m,a[M],cha[M],ans=-1e18,id;
bool vis[M]={0};
inline int Max(int a,int b)
{	return a>b?a:b;
}
inline void dfs(int usd,int st)
{	if(usd>m)
	{	ans=Max(ans,st-1);
		return;
	}
	if(usd==m)
	{	ans=Max(ans,st);
		return;
	}
	for(int i=id;i<=n;i++)
		if(!vis[i])
		{	vis[i]=1;
			int ch=0;
			for(int j=i+1;j<=id;j++)
				ch+=cha[j];
			for(int j=i;j>id;j--)
				ch+=cha[j];
			dfs(usd+ch,st+1);
			vis[i]=0;
		}
}
signed main()
{	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		cha[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
		id=i,vis[i]=1,dfs(cha[i],2);
	cout<<ans<<"\n";
	return 0;
}
//²»ÕùÁË
//I Love CCF  I Love OI 
