#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5e5+10;
long long w[N],cha[N],s[N],s_1[N];
int res;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<n;i++)
	{
		cha[i]=w[i+1]-w[i];
		s_1[i]=cha[i]+s_1[i-1];
	}
	for(int i=1;i<n;i++)
		s[i]=s[i-1]+i*cha[i];
	for(int len=1;len<n;len++)
	{
		unsigned long long min_used=1e18;
		for(int l=0;l+len<n;l++)
		{
			int r=l+len;
			min_used=min(min_used,(unsigned long long )(s[r]-s[l])-l*(s_1[r]-s_1[l]));
		}
		if(min_used>=m)
		{
			res=len;
			if(m==min_used)res++;
			break;
		}
	}
	cout<<res;
}
