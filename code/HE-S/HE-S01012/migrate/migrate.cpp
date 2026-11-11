#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<deque>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
const int N=2e6+5;
int c,T;
int n;intt m;
intt a[N];int f[N],g[N],cnt[N];
std::deque<int> q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		for(int i=1;i<=n;i++) f[i]=g[i]=0;
		scanf("%d",&n),scanf("%lld",&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int ans=0;
		for(int l=1;l<=n;l++)
		{
			for(int i=1;i<=n;i++) cnt[i]=0;
			while(!q.empty()) q.pop_back();
			q.push_back(l);cnt[0]=1;f[l]=0,g[l]=1;
			for(int r=l+1,j=l;r<=n;r++)
			{
				while(!q.empty()&&a[q.front()]+m<a[r]) q.pop_front();
				while(a[j]+m<a[r]) cnt[f[j]]-=g[j],j++;
				if(q.empty()) break;
				f[r]=f[q.front()]+1;
				g[r]=cnt[f[r]-1];
				cnt[f[r]]+=g[r];
				while(!q.empty()&&f[q.back()]>=f[r]) q.pop_back();
				q.push_back(r);
				ans+=(g[r]==2);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
