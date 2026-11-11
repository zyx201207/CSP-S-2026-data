#include<bits/stdc++.h> 
using namespace std;
const int maxn=5*1e5+10;
long long n,m,a[maxn],cnt,ans,maxx; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int j=i-1;
		cnt=0,ans=1;
		do
		{
			cnt+=a[i]-a[j];
			
			if(cnt>m)break;if(j<1)break;
			ans++;
			j--;
			if(j<1)break;
		}while(cnt<=m&&j>=1);
		maxx=max(ans,maxx);
		
	}
	cout<<maxx;
}
