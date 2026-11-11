//当且仅当海鸟可以飞到(l+r)/2,(l+r)/2+1两座岛
//且无法从l飞到(l+r)/2+2，从(l+r)/2-1飞到r时，是符合条件的一组岛屿 
//枚举右端点，并找出第二个比大于等于r-d的数k，找到第一个比k-d大的数，即为所求 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d,p[1000001],l[1000001],r[1000001]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		memset(p,0,sizeof(p));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>p[i],l[i]=0,r[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]-d>=p[1]&&p[i]-d<=p[i-1])
				r[i]=r[lower_bound(p+1,p+n+1,p[i]-d)-p]+1;
			else
				r[i]=1;			
		}
		for(int i=n;i>=1;i--)
		{
			if(p[i]+d<=p[n]&&p[i]+d>=p[i+1])
				l[i]=r[lower_bound(p+1,p+n+1,p[i]+d)-p+1]+1;
			else
				l[i]=1;			
		}	
		for(int i=1;i<=n;i++)
		{
			int tp=lower_bound(p+1,p+n+1,p[i]-d)-p;
			if(tp<=i-2&&p[tp+1]-d>=p[1])
			{
				cout<<p[i]<<' '<<p[(int)(lower_bound(p+1,p+n+1,p[tp+1]-d)-p)]<<endl;
				cout<<r[(int)(lower_bound(p+1,p+n+1,p[tp+1]-d)-p)]<<' '<<l[i]<<endl<<endl;
				ans+=r[(int)(lower_bound(p+1,p+n+1,p[tp+1]-d)-p)]*l[i];
			}
				
		}
		cout<<endl<<"ANSWER "<<ans<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

