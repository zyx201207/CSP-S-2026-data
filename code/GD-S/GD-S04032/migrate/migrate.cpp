#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t,n,d,a[N],f[N],pre[N],p[N],dis[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int l=1,r=1,x,cnt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			f[i]=0;
			pre[i]=0;
		}
		f[1]=1;
		pre[1]=1;
		for(int i=1;i<=n;i++)
		{
			l=i,r=i;
			f[i]=1;
			pre[i]=1;
			dis[i]=0;
			
			for(int j=i+1;j<=n;j++)
			{
				while(a[j]-a[l]>d)
				l++;
				if(r<l)
				r=l;
				while(dis[r+1]==dis[l]&&r+1<j)
				{
					r++;
				}
//				cout<<j<<" "<<l<<" "<<r<<endl;
				f[j]=pre[r]-pre[l-1];
				dis[j]=dis[l]+1;
				pre[j]=pre[j-1]+f[j];
				if(f[j]==2)
				{
					ans++;
				}
			}
//			cout<<":";
//			for(int j=i+1;j<=n;j++)
//			{
//				cout<<f[j]<<" ";
//			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
