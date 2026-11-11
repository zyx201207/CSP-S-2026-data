#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=-2e9,f1,f2,t,ans;
bool mysort(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=i)f1=1;
		if(i==1)t=a[1]-a[0];
		if(i!=0&&a[i]-a[i-1]!=t)f2=1;
		
	}
	if(f1==0){
		long long k=0;
		while(1){
			if(m<k)break;
			m-=k;
			ans++;
			k++;
		}
		printf("%lld",ans);
		return 0;
	}
	if(f2==0)
	{
		long long k=0,num=a[1]-a[0];
		while(1){
			if(m<k)break;
			m-=k;
			ans++;
			k+=num;
			
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a,a+n,mysort);
	for(int i=0;i<n;i++)
	{
		long long ans=0,k=m;
		for(int j=i;j<n;j++){
			if(a[i]-a[j]<=k){
				k-=a[i]-a[j];
				ans++;
			}
			else break;
		}
		maxn=max(maxn,ans);
	}
	printf("%lld",maxn);
	return 0;
}
