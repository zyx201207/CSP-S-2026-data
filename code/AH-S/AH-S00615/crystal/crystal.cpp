#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,size[N],sum[N],ans=0;
long long lrtok(long long l,long long  r)
{
	long long k=r;
	return size[k]*(r-l+1)-(sum[r]-sum[l-1]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>size[i];
	}
	stable_sort(size+1,size+n+1);
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+size[i];
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			//cout<<"{"<<mid<<","<<lrtok(mid,i)<<"<?>"<<m<<"} ";
			if(lrtok(mid,i)<=m)
			{
				//cout<<"Enough";
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		//cout<<"To set to "<<i<<"max"<<l<<"-"<<i<<"\n";
		if(i-l+1>ans) ans=i-l+1;
	}
	cout<<ans;
	return 0;
}
//5 5 1 2 4 8 9
