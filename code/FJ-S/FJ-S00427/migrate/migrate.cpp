/*
T3 migrate
15:10 ÇÃÁË¸ön^3µÄdp£¬24pts 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=2e6+5;
const ljl inf=1e18;
int c,T,n;
ljl d,a[N],ans,f[N],v[N];
namespace QQQQ{
	int dq[200005],l,r;
	void solve(int u)
	{
		for(int i=1;i<=n;++i)f[i]=inf,v[i]=0;
		f[u]=0;v[u]=1;
		l=n+1;r=n+1;dq[l]=u;
		for(int i=u+1;i<=n;++i)
		{
			while(l<=r&&a[i]-a[dq[l]]>d)++l;
			if(l>r)continue;
			f[i]=f[dq[l]]+1;
			for(int k=l;k<=r;++k)
			{
				if(f[dq[k]]+1!=f[i])break;
				v[i]+=v[dq[k]];
				if(v[i]>2)v[i]=3;
			}
			if(v[i]>2)v[i]=3;
			while(l<=r&&f[i]<f[dq[r]])--r;
			++r;dq[r]=i;
		}
		return;
	}
	void Main()
	{
		for(int i=1;i<n;++i)
		{
			solve(i);
			for(int j=i+1;j<=n;++j)
				if(v[j]==2)++ans;
		}
		cout<<ans<<'\n';
		return;
	}
}
void solve(int u)
{
	for(int i=1;i<=n;++i)f[i]=inf,v[i]=0;
	f[u]=0;v[u]=1;
	for(int i=u+1;i<=n;++i)
	{
		for(int j=i-1;j>=u;--j)
		{
			if(a[i]-a[j]>d)break;
			if(f[i]>f[j]+1)
			{
				f[i]=f[j]+1;
				v[i]=v[j];continue;
			}
			if(f[i]==f[j]+1)
			{
				v[i]+=v[j];
				if(v[i]>2)v[i]=3;
				continue;
			}
		}
	}
	return;
}
void Main()
{
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n>500){QQQQ::Main();return;}
	for(int i=1;i<n;++i)
	{
		solve(i);
		for(int j=i+1;j<=n;++j)
			if(v[j]==2)++ans;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)Main();
	return 0;
}

