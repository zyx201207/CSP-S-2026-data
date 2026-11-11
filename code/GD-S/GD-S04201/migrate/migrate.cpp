#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000010];
int otpt=0;
//4hours->too short AFO 
void solve()
{
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			
			if(a[j]-a[i]>2*m)break;
			if(a[j]-a[i]<=m)continue;
			int pos;
			for(int p=i;p<=j;p++)
			{
				if(a[p]>m)
				{
					pos=p-1;
					break;
				}
			}
			int res=0;
			for(int p=-2;p<=2;p++)
			{
				if(pos+p<0||pos+p>=n)continue;
				if(a[pos+p]-a[i]<=m&&a[j]-a[pos+p]<=m)res++;
			}
			if(res!=2)continue;
			ans++;
		}
	}
	otpt+=ans;
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t,cnt;
	cin>>c>>t;
	while(t--)
	{
		otpt=0;
		cnt=1;
		cin>>n>>m;
		cin>>a[1];
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			a[i]-=a[1];
			a[i]++;
		}
		a[1]=1;
		solve();
		cout<<otpt<<endl;
	}
	
 	return 0;
}

