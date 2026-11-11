#include<cstdio>
using namespace std;
long long a[1000000],n,d,ans,sum;
void dfs(long long x,long long y){
	if(x==y){
		ans++;
		return;
	}
	if(x>y){
		int z=x;
		x=y,y=z;
	}
	for(long long i=x;i<n&&a[i]-a[x]<=d;i++){
		dfs(i,y);
	}
}
int main()
{
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld %lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld %lld",&n,&d);
		for(long long i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long gc=a[1]-a[0];
		if(c>=11){
			if(d/gc>=2&&n*gc>d)
				printf("%lld\n",n-d/gc*2+1);
			else
				printf("0\n");
		}else{
			for(long long i=0;i<n;i++)
				for(long long j=0;j<n;j++){
					sum=0;
					dfs(i,j);
					if(sum==2)
						ans++;
				}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
