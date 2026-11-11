#include<bits/stdc++.h>
using namespace std;
#define mid (len>>1)
void merge(long long *num,int len)
{
	long long ans[len];
	int i=0,j=mid,k=0;
	while(i<mid&&j<len)
	{
		if(num[i]<=num[j])
			ans[k++]=num[i++];
		else ans[k++]=num[j++];
	}
	while(i<mid)ans[k++]=num[i++];
	while(j<len)ans[k++]=num[j++];
	for(int i=0;i<len;i++)
		num[i]=ans[i];
}
void merge_sort(long long *num,int len)
{
	if(len<=1)return;
	merge_sort(num,len-mid);
	merge_sort(num+mid,len-mid);
	merge(num,len);
}
#undef mid
int n;
long long m;
long long a[500005];
long long sum[500005];
int ans;
template<typename T>
int rf(T f[],T fs,int i,int l,int r)
{
	while(l!=r)
	{
		int mid=(l+r)>>1;
		if((i-mid)*a[i]-(f[i-1]-f[mid-1])>fs)l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
//	sort(a+1,a+n+1);
	merge_sort(a+1,n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i],
		ans=max(ans,i-rf(sum,m,i,1,i)+1);
//		cerr<<i<<":"<<rf(sum,m,i,1,i)<<"\n";
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

*/
