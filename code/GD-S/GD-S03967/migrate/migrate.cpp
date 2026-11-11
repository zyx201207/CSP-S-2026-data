#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,T,n,k[N],dis[N],f[N],ans,sum,last,s[N];
__int128 m;
string sss;
vector<int> v;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)//¶à²âÇå¿Õ 
	{
		ans=0;
		cin>>n>>sss;
		m=0;
		for(int i=1;i<=sss.size();i++) m=m*10+(sss[i-1]-'0');
		for(int i=1;i<=n;i++) cin>>k[i-1];
		for(int i=1;i<=n;i++)
		{
			for(int t=i+1;t<=n;t++) dis[t]=0,f[t]=0;
			v.clear();
			int l=i;
			dis[i]=0;
			for(int t=i+1;t<=n;t++)
			{
				while(k[t-1]-k[l-1]>m && l<t) l++;
				if(l==t) break;
				else dis[t]=dis[l]+1; 
			}
			for(int i=1;i<=n;i++) s[i]=0;
			f[i]=1;
			sum=1,l=i,last=i,s[0]=1;
			for(int t=i+1;t<=n;t++)
			{
				while(k[t-1]-k[l-1]>m && l<t) sum-=f[l],l++;
				if(l==t) break;
				if(dis[l]==dis[t]-1) f[t]=sum-s[dis[t]];
				else f[t]=s[dis[t]-1];
				sum+=f[t];
				s[dis[t]]+=f[t];
				if(f[t]==2) ans++;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
}
