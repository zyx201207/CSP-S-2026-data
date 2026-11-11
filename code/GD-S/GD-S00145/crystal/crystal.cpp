#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans=0;
bool tpA=true,tpB=true;
long long d=-1,tpa[500005],tpat=0,tpb[500005],tpbt=0;;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==0){cout<<0;return 0;} 
	if(n==1){cout<<1;return 0;}
	if(n==2)
	{
		cin>>a[1]>>a[2];
		if(m>=abs(a[2]-a[1]))cout<<2;
		else cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		tpa[i]=tpa[i-1]+tpat;tpat++;
		//cout<<i<<" "<<tpa[i]<<" "<<tpat<<endl;
		if(a[i]!=i)tpA=false;
		if(i>=3&&d==a[i]-a[i-1]);
		else if(i>=3)tpB=false;
		if(i>=2)d=a[i]-a[i-1];
		tpb[i]=tpb[i-1]+d*tpbt;
		tpbt++;
	}
	//for(int i=1;i<=n;i++)cout<<tpa[i]<<" ";
	//for(int i=1;i<=n;i++)cout<<tpb[i]<<" ";
	if(tpA)
		for(int i=n;i>=1;i--)if(m>=tpa[i]){cout<<i;return 0;}
	if(tpB)
		for(int i=n;i>=1;i--)if(m>=tpb[i]){cout<<i;return 0;}
	/*long long l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		long long temp=0;
		for(int i=1;i<mid;i++)temp+=a[mid]-a[i];
		if(temp<=m)ans=max(ans,mid),l=mid+1;
		else r=mid;
		//cout<<l<<' '<<r<<" "<<ans<<" "<<temp<<endl;
	}*/
	for(long long i=1;i<=n;i++)
	{
		long long temp=0,tans=0;
		for(long long j=i-1;j>=1;j--)
		{
			temp+=a[i]-a[j];
			if(temp>m)
			{
				tans=max(tans,i-j);
				break;
			}
		}
		if(tans==0&&temp>0)tans=max(tans,i);
		ans=max(ans,tans);
	}cout<<ans;
	return 0; 
} 
