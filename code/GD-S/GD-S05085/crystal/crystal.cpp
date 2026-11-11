#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=a[i]-a[1];
	if(n>=5)
	{
		bool vis=true;
		long long d=s[3]-s[2];
		for(int i=3;i<=n;i++)
			if(s[i]-s[i-1]!=d) vis=false;
		if(vis)
		{
			long long q=1;
			for(int i=2;i<=n;i++)
			{
				if((s[2]+s[i])*(i-1)/2>m) break;
				q++;
			}
			printf("%lld",q);
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i+1]==0 and i+1<=n) continue;
		long long sum=0,j=i,cnt=1;
		while(j>=2)
		{
			int q=s[i]-s[j-1];
			sum+=q;
			if(sum>m) break;
			cnt++,j--;
		}
		ans=max(cnt,ans);
	}
	printf("%lld",ans);
	return 0;
}
