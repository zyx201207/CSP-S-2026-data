#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000010],pre[2000010],nt[2000010],d[2000010][2];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	for(int op=1;op<=T;op++)
	{
		int n,D,ans=0;cin>>n>>D;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=n,j=n;i>=1;i--)
		{
			while(j-1>=1&&x[j-1]>=x[i]-D)j--;
			pre[i]=j;
		}
		for(int i=1,j=1;i<=n;i++)
		{
			while(j+1<=n&&x[j+1]<=x[i]+D)j++;
			nt[i]=j;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=d[pre[i]][1];
			if(nt[pre[i]]==i)d[i][1]+=d[pre[i]][1];
			if(pre[i]+1<i)
			{
				ans+=d[pre[i]+1][0];
				if(nt[pre[i]+1]==i)d[i][1]+=d[pre[i]+1][0];
			}
			d[nt[i]][0]++;
			if(pre[nt[i]]==i)d[nt[i]][0]+=d[i][0];
		}
		//cout<<"ตฺ"<<op<<"ื้"<<endl;
		cout<<ans<<endl;
//		cout<<n<<' '<<D<<endl;
//		for(int i=1;i<=n;i++)cout<<x[i]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<pre[i]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<nt[i]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<d[i][0]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<d[i][1]<<' ';cout<<endl;
		for(int i=1;i<=n;i++)x[i]=pre[i]=nt[i]=d[i][0]=d[i][1]=0;
	}
	return 0;
}
