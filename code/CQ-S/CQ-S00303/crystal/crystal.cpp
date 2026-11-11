#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int len=n;len>=1;len--)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int temp=sum[i+len-1]-sum[i-1]+m;
			if(temp/len>=a[i+len-1])
			{
				cout<<len;
				return 0;
			}
		}
	}
}

