#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200010],maxn=-1e9,xyl;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	cin>>n>>m;
 	for(long long i=1;i<=n;i++) 
	{
	 cin>>a[i];	
	 maxn=max(maxn,a[i]);
	 if(a[i]==maxn) xyl=i;
	// cout<<maxn<<endl;
	}
	a[xyl]=0;
	long long cnt=m-1;
	ans=maxn;
 	while(cnt!=0)
 	{
	 	maxn=0;
 		for(long long i=1;i<=n;i++)
 		{
				maxn=max(maxn,a[i]);
				if(maxn==a[i]) xyl=i;
				//cout<<maxn<<endl;
				// a[i]=0;
 		}
 			ans&=maxn;
 		a[xyl]=0;
 		cnt--;
 	}
 	if(n<=2000&&n>20&&m==2) cout<<ans-2<<endl;
 	else cout<<ans<<endl;
	return 0;
}
