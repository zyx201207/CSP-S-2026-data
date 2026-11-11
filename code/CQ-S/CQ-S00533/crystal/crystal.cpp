#include<bits/stdc++.h>
using namespace std;
namespace Ganlai
{
#define int long long
	const int N=5e5+1,INF=9e18;
	int n,m,a[N],s[N],ans;
	inline bool checker(const int &l,const int &r)
	{
//		printf("%lld %lld %lld %lld\n",l,r,a[r]*(r-l+1)-(s[r]-s[l-1]),m);
		return a[r]*(r-l+1)-(s[r]-s[l-1])<=m;
	}
	inline int binary_search(const int &L,const int &R)
	{
//		printf("%lld %lld:\n",L,R);
		int l=L,r=R;
		while(l<r)
		{
			const int mid=(r-l)/2+l;
			if(checker(L,mid))
				l=mid+1;
			else
				r=mid;
		}
//		printf("%lld\n",l-1);
		return l-1;
	}
	void main()
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%lld",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;++i)
			ans=max(ans,binary_search(i,n)-i+1);
		printf("%lld\n",ans);
	}
#undef int
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Ganlai::main();
	return 0;
}
//	T:O(nlogn)
//	M:3752 KB
