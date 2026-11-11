#include<bits/stdc++.h>
using namespace std;
long long c,t,n[2000005],d[2000005],x[2000005],l,r,cnt,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	l=1,r=l+3;
	for(long long i=1;i<=t;i++) 
	{
		cin>>n[i]>>d[i];
		cnt=0;
		for(long long j=1;j<=n[i];j++)
		{
			cin>>x[j];
		}
		for(long long j=l;j<r;j++)
		{
			if(x[r]-x[j]<=d[i]) cnt++;
		}
		if(cnt==2) ans++;
		if(x[r]-x[l]<d[i]&&x[3]-x[1]==x[4]-x[2]) cout<<n[i]-3<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
