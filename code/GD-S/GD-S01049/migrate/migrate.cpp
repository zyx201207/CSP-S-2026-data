#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],ans,f[N],g[N],lst[N],cnt[N],b[N];
int chk(int x)
{
	for(int i=x;i<=n;i++) f[i]=N+5,g[i]=0,lst[i]=0,cnt[i]=0;
	for(int i=0;i<=n;i++) b[i]=0;
	f[x]=0,lst[x]=x,b[0]=1;
	int res=0;
//	cout<<x<<":\n"; 
	for(int i=x+1,j=x;i<=n;i++)
	{
		while(j<i&&a[i]-a[j]>d) b[f[j]]--,j++;
		if(i==j) break;
//		cout<<"i="<<i<<" "<<f[i]<<" j="<<j<<" "<<b[f[j]]<<"\n";
		f[i]=f[j]+1,g[i]=b[f[j]],b[f[i]]++,lst[i]=j;
		if(g[i]<3&&cnt[j]!=-1) cnt[i]=cnt[j]+(g[i]==2),res+=(cnt[i]==1);
		else cnt[i]=-1;
	}
//	for(int i=x;i<=n;i++)
//		cout<<f[i]<<" "<<g[i]<<" "<<lst[i]<<" "<<cnt[i]<<"\n";
//	cout<<"res="<<res<<"\n\n";
	return res;
}
void sol()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	for(int i=1;i<=n;i++) ans+=chk(i);
	cout<<ans<<"\n";
}
void solx()
{
	int st=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[1]<=d&&a[n]-a[i]<=d){ st=i;break;}
	}
	ans=0;
	if(st>2)
	{
		int l=st+1,r=n;
		while(l<=n&&a[l]-a[st-2]<=d) l++;
		while(r>st&&a[r]-a[st-1]>d) r--;
		for(int i=st-1;i>0;i--)
		{
			if(a[st+1]-a[i]<=d) continue ;
			if(l<=r) ans+=(r-l+1);
		}
	}
	if(n-st+1>2)
	{
		int l=st-1,r=1;
		while(l>0&&-a[l]+a[st+2]<=d) l--;
		while(r<st&&-a[r]+a[st+1]>d) r++;
		for(int i=st+1;i<=n;i++)
		{
			if(a[i]-a[st-1]<=d) continue ;
			if(l>=r) ans+=(l-r+1);
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){ while(t--) solx();return 0;}
	while(t--) sol();
	return 0;
}

