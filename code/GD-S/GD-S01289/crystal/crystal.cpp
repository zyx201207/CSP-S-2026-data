#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,w_ans,l,r,w_mid,w_temp;
long long m,a[500005],w_sum[500005];
int main()
{
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		w_sum[i]=w_sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		l=1;
		r=i;
		w_temp=i;
		while(l<=r)
		{
			w_mid=l+r>>1;
			if(a[i]*(i-w_mid+1)-(w_sum[i]-w_sum[w_mid-1])<=m)
			{
				w_temp=w_mid;
				r=w_mid-1;
			}
			else
				l=w_mid+1;
		}
//		printf("[%d,%d]\n",w_temp,i);
		w_ans=max(w_ans,i-w_temp+1);
	}
	printf("%d",w_ans);
	return 0;
}
