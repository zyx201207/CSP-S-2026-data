#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,m,ans;
long long v[N+1],b[N+1];
long long t[N+1]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	sort(v+1,v+1+n);
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" ";
		//cout<<v[i]<<"\n";
		long long cnt=1;
		memset(t,0,sizeof(t));
		t[0]=INT_MAX,t[n+1]=INT_MAX;
		for(int j=1;j<=n;j++)
		{
			t[j]=abs(v[i]-v[j]);
			//cout<<t[j]<<" ";
		}
		//cout<<v[i]<<"\n";
		//for(int j=1;j<=n;j++)
		//	cout<<"p"<<t[j]<<" ";
		//cout<<"\n";
		long long z=m;
		long long l=i-1,r=i+1;
		while(z>=0&&l>=0&&r<=n+1)
		{
			//cout<<t[l]<<" "<<t[r]<<"\n";
			if(t[l]<t[r])
			{
				z-=t[l];
				if(z>=0)
					cnt++;
				l--;
			}else
			{
				z-=t[r];
				if(z>=0)
					cnt++;
				r++;
			}
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
