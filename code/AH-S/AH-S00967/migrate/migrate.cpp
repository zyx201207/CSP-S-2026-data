#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
long long a[2000005];
int ld[2000005],rd[2000005];
long long lsum[2000005],rsum[2000005];
long long lpsum[2000005],rpsum[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tid,T;
	cin>>tid>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ld[1]=1;
		for(int i=2;i<=n;i++)
		{
			ld[i]=ld[i-1];
			while(a[i]-a[ld[i]]>d)
				ld[i]++;
		}
		rd[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			rd[i]=rd[i+1];
			while(a[rd[i]]-a[i]>d)
				rd[i]--;
		}
		lpsum[0]=rpsum[n+1]=0;
		rd[0]=0,ld[n+1]=n+1;
		for(int i=1;i<=n;i++)
		{
			//cout<<rd[i]<<' ';
			lsum[i]=0;
			if(ld[i]==ld[i+1])
				lsum[i]=1;
			else
				lsum[i]=lsum[ld[i]]+ld[i+1]-ld[i];
		}
		//cout<<'\n';
		for(int i=n;i>=1;i--)
		{
			rsum[i]=0;
			if(rd[i]==rd[i-1])
				rsum[i]=1;
			else
				rsum[i]=rsum[rd[i]]+rd[i]-rd[i-1];
		}
		//for(int i=1;i<=n;i++)
		//cout<<'('<<lsum[i]<<' '<<rsum[i]<<')'<<endl;
		long long ans=0;
		for(int i=1;i<=n;i++)//size_j!=1
		{
			int t1=rd[i],t2=t1-1;
			if(t2<=i)
				continue;
			int j=rd[t1];
			if(j==t1)
				continue;
			if(rd[t2-1]>=j || rd[t2]<j)
				continue;
			//cout<<i<<' '<<j<<endl;
			//cout<<(ld[t2]==i?lsum[i]:1)<<' '<<rsum[j]-1<<endl;
			ans+=(ld[t2]==i?lsum[i]:1)*(rsum[j]-1);
		}
		for(int i=n;i>=1;i--)//size_i!=1 && size_j==1
		{
			int t1=ld[i],t2=t1+1;
			if(t2>=i)
				continue;
			int j=ld[t1];
			if(j==t1)
				continue;
			if(ld[t2+1]<=j || ld[t2]>j)
				continue;
			ans+=lsum[j]-1;
		}
		for(int i=1;i<=n;i++)//size_i==1 && size_j==1
		{
			int t1=rd[i],t2=t1-1;
			if(t2<=i)
				continue;
			ans+=rd[t2]-rd[t2-1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
