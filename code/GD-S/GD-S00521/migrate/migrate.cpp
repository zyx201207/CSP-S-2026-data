#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,x[N],f[N],g[N],num[N],ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++)
		{
			//cout<<"开始"<<i<<endl; 
			for (int j=1;j<=n;j++) num[j]=0;
			f[i]=0,g[i]=1,num[0]=1;
			int p=i;
			for (int j=i+1;j<=n;j++)
			{
				//cout<<x[j]<<endl;
				while (x[j]-x[p]>d) num[f[p]]-=g[p],p++;
				//cout<<j<<" "<<p<<endl;
				if (p==j) break;
				f[j]=f[p]+1,g[j]=num[f[p]];
				num[f[j]]+=g[j];
				//cout<<"数量"<<g[j]<<endl;
				if (g[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
