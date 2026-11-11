#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
long long b[500005],c[500005];
bool cmp(long long k,long long kk)
{
	return k>kk;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i-1]-a[i];
	}
	
	for(long long i=n;i>=1;i--)
	{
		long long o=m,j;
		for(j=i-1;j>=1;j--)
		{
			o-=b[j+1]*(i-j);
			if(o<0)
			{
				ans=max(ans,i-j);
				break;
			}
		}
		if(o>=0)
		{
			ans=max(i,ans);
			break;
		}
	}
	cout<<ans;
	return 0;
}
