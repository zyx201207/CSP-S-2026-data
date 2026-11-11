#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500100];
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans = 0;
		cin>>n>>m;
		for(int j=1;j<=n;j++)
			cin>>a[j];
		if(n==1||n==2||n==3)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==4)
		{
			//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
			if((a[4]-a[1]>m)&&(a[3]-a[1]<=m)&&(a[4]-a[2]<=m))
			{
				cout<<1<<endl;
				continue;
			}
		}
		if(n==5)
		{
		//	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;
			if((a[4]-a[1]>m)&&(a[3]-a[1]<=m)&&(a[4]-a[2]<=m))
				ans++;
			if((a[5]-a[2]>m)&&(a[4]-a[2]<=m)&&(a[5]-a[3]<=m))
				ans++;
			//if((a[5]-a[1]>m)&&(a[4]-a[1]<=m)&&(a[5]-a[2]<=m)&&(a[3]-a[1]>))
			//	ans++;
		}
		if(n==6)
		{
			if((a[4]-a[1]>m)&&(a[3]-a[1]<=m)&&(a[4]-a[2]<=m))
				ans++;
			if((a[5]-a[2]>m)&&(a[4]-a[2]<=m)&&(a[5]-a[3]<=m))
				ans++;
			if((a[6]-a[3]>m)&&(a[5]-a[3]<=m)&&(a[6]-a[4]<=m))
				ans++;
			if((a[6]-a[1]>m)&&(a[5]-a[1]>m)&&(a[6]-a[2]>m)&&(a[4]-a[1]<=m)&&(a[6]-a[3]<=m))
				ans++; 
		}
		if(n==7)
		{
			if((a[4]-a[1]>m)&&(a[3]-a[1]<=m)&&(a[4]-a[2]<=m))
				ans++;
			if((a[5]-a[2]>m)&&(a[4]-a[2]<=m)&&(a[5]-a[3]<=m))
				ans++;
			if((a[6]-a[3]>m)&&(a[5]-a[3]<=m)&&(a[6]-a[4]<=m))
				ans++;
			if((a[7]-a[4]>m)&&(a[6]-a[4]<=m)&&(a[7]-a[5]<=m))
				ans++;
			if((a[6]-a[1]>m)&&(a[5]-a[1]>m)&&(a[6]-a[2]>m)&&(a[4]-a[1]<=m)&&(a[6]-a[3]<=m))
				ans++;
			if((a[7]-a[2]>m)&&(a[6]-a[2]>m)&&(a[7]-a[3]>m)&&(a[5]-a[2]<=m)&&(a[7]-a[4]<=m))
				ans++;
		}
		if(n==8)
		{
			if((a[4]-a[1]>m)&&(a[3]-a[1]<=m)&&(a[4]-a[2]<=m))
				ans++;
			if((a[5]-a[2]>m)&&(a[4]-a[2]<=m)&&(a[5]-a[3]<=m))
				ans++;
			if((a[6]-a[3]>m)&&(a[5]-a[3]<=m)&&(a[6]-a[4]<=m))
				ans++;
			if((a[7]-a[4]>m)&&(a[6]-a[4]<=m)&&(a[7]-a[5]<=m))
				ans++;
			if((a[8]-a[5]>m)&&(a[7]-a[5]<=m)&&(a[8]-a[6]<=m))
				ans++;
			if((a[6]-a[1]>m)&&(a[5]-a[1]>m)&&(a[6]-a[2]>m)&&(a[4]-a[1]<=m)&&(a[6]-a[3]<=m))
				ans++;
			if((a[7]-a[2]>m)&&(a[6]-a[2]>m)&&(a[7]-a[3]>m)&&(a[5]-a[2]<=m)&&(a[7]-a[4]<=m))
				ans++;
			if((a[8]-a[3]>m)&&(a[7]-a[3]>m)&&(a[8]-a[4]>m)&&(a[6]-a[3]<=m)&&(a[8]-a[5]<=m))
				ans++;
			if( ( a[8] - a[1] > m ) && ( a[5] - a[1] > m) && ( a[8] - a[5] > m) && ( a[4] - a[1] <= m) && ( a[7] - a[4] >=m) && ( a[8] - a[5] >= 0) && ( a[5] - a[2] >= m) )
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}


