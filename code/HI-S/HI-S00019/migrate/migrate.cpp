#include<bits/stdc++.h>
#define int long long
using namespace std;

//草拟吗的假了tm为啥暴力也假啊啊啊啊啊啊啊操 傻逼T3浪费时间md没时间做T2T4了 
const int N=2e6+10;
int C,T,n,d,x[N];
int ans,last,lastlast;

int check(int i)
{
	if(i<2||i>n-2)return 0;
	if(x[i+1]-x[i-1]>d||x[i+2]-x[i]>d||x[i+2]-x[i-1]<=d)return 0;
	return 1;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0); 
	cin>>C>>T;while(T--)
	{
		last=0,lastlast=0,ans=0;
		cin>>n>>d;
//		ans=0;memset(f,0x3f,sizeof f);memset(t,0,sizeof t);
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++)
		{
			if(last==0&&x[i+1]-x[i]<=d)last=i;
			else if(x[i+1]-x[i]>d)
			{
				if(lastlast)
				{
					ans+=(last-lastlast)*(i-last-1);
				}
				last=0,lastlast=0;
			}
			else if(check(i)==1)
			{
//				puts("??????");
				if(lastlast)
				{
					ans+=(last-lastlast)*(i-last);
				}
				lastlast=last,last=i;
			}
			else if(check(i)==2&&lastlast)ans++;
//			cout<<last<<" "<<lastlast<<"\n";
		}
//		for(int i=1;i<=n;i++)
//		{
//			int j=lower_bound(x+1,x+n+1,x[i]+d-1)-x;
//			int k=lower_bound(x+1,x+n+1,x[j]+d)-x;
//			int l=upper_bound(x+1,x+n+1,x[k]-d)-x;
//			cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
//			if(x[l]-x[i]<=d&&l>j&&k<=n&&i<k)ans++;
//		}
		if(lastlast)ans+=(last-lastlast)*(n-last-1);
		cout<<ans<<"\n";
//		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(x[j]-x[i]<=d)
//		{
//			f[i][j]=1;
//			t[i][j]=1;
//		}
//		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)
//		{
//			int temp=f[i][i+k]==1?1:0x3f3f3f3f3f3f3f3f,cnt=0;
//			for(int j=i+1;j<i+k;j++)
//				if(temp>f[i][j]+f[j][i+k])temp=f[i][j]+f[j][i+k];
//			for(int j=i+1;j<i+k;j++)
//				if(temp==f[i][j]+f[j][i+k])cnt++;
//			f[i][i+k]=temp;
//			if(cnt==2)ans++;
//		}
//		cout<<ans<<"\n";
	}
	return 0;
}
