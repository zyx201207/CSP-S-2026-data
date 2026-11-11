//第一道题 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
//vector<long long> a;
//vector<long long> f;//前缀和 
long long a[500005];
long long f[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	//a.resize(n+5,0);
	//f.resize(n+5,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	//sort(a.begin()+1,a.begin()+n+1);
	sort(a+1,a+n+1);
	long long ans=1;
	f[1]=a[1];
	for(int i=2;i<=n;i++)//终点 
	{
		f[i]=f[i-1]+a[i];//前缀和 
		for(int j=i-ans;j>=1;j--)//起点 
		{
			long long pq=(i-j+1);
			long long tot=a[i]*pq-(f[i]-f[j-1]);
			/*printf("区间:%lld %lld\n",i,j);
			printf("所需总和:%lld\n",a[i]*(i-j+1));
			printf("现有:%lld\n",(f[i]-f[j-1]));
			printf("差:%lld\n\n",tot);*/
			if(tot<=m)
			{
				//printf("Get:%lld\n\n",i-j+1);
				ans=max(ans,pq);
			}else{
				break;
			}
		}
	}
	printf("%lld",ans);
	
	return 0;
}
