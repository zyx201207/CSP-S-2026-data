#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=2e6+5;
int i,j,k,c,t,n,d,x[N],ans,la=1,sum,ecls[N],ecle[N],cnt,fl=1,dp[305][305],ansss[305][305];
int find(int st,int num)
{
	int l=st,r=n+1,mid=(l+r)/2;
	while(l<r)
	{
		if(x[mid]>num)r=mid,mid=(l+r)/2;
		else l=mid+1,mid=(l+r)/2;
	}
	return mid;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<"aaa";
	//cout<<find(1,te)<<endl;
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0,cnt=0,fl=1;
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>x[i];
		for(i=2;i<n;i++)if(i>1&&x[i]*2!=x[i-1]+x[i+1])fl=0;
		if(fl==1)
		{
			int cha=x[n]-x[n-1];
			if(cha==0)cout<<0<<endl;
			else if(2*cha>d)cout<<0<<endl;
			else cout<<max(n-2*d/cha+1,0ll)<<endl;
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)dp[i][j]=dp[j][i]=1;
				else dp[i][j]=dp[j][i]=n+1;
				ansss[i][j]=0;
			}
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)if(k!=i&&k!=j)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)if(k!=i&&k!=j&&dp[i][k]+dp[k][j]==dp[i][j]&&dp[i][j]!=i-j)ansss[i][j]++;
			}
		}
		//cout<<'a'<<endl;
		for(i=1;i<=n;i++)cout<<"  "<<i<<"   ";
		cout<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)cout<<dp[i][j]<<' '<<ansss[i][j]<<"   ";
			cout<<endl;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)if(ansss[i][j]==2&&dp[i][j]<abs(i-j))ans++;
		}
		cout<<ans/2<<endl;
		//x[n+1]=x[i];
		//for(i=1;i<=n-2;i++)
		//{
		//	int p=find(i,x[i]+d),p2=find(p-1,x[p-1]+d)-1;
		//	if(p==n+1)break;
		//	//cout<<p<<endl;
		//	if(p==i+2)continue;
		//	if(x[p]ecls[++cnt]=i,ecle[cnt]=p;
		//}
		//cout<<cnt<<endl;
		//ecle[0]=1,ecls[++cnt]=n;
		//for(i=1;i<cnt;i++)cout<<ecls[i]<<' '<<ecle[i]<<endl;
		//for(i=1;i<cnt;i++)
		//{
		//	if(ecls[i]>=ecle[i-1]&&ecls[i+1]>=ecle[i])ans+=(ecls[i]-ecle[i-1]+1)*(ecls[i+1]-ecle[i]+1);
		//	else if(ecls[i]>=ecle[i-1])ans+=(ecls[i]-ecle[i-1]
		//	else 
		//}
		//cout<<ans<<endl;
	}
}
