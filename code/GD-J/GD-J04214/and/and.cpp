#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+5;
int n,m;
int a[N],ans;
vector<int> v;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		v.push_back(i);
	}
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		vector<int> nw;
		for(int j:v)
		{
			if((a[j]>>i)&1) 
			{
				nw.push_back(j);
				++cnt;
			}
		} 
		if(cnt>=m) 
		{
			ans+=(1<<i);
			v=nw;
		}
	}
	printf("%lld",ans);
	return 0;
}
