#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,len=1,a[N],b[N],pre[N];
int sum(int l,int r,int delta)
{
	return pre[r]-pre[l-1]-(r-l+1)*delta;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[1],pre[i]=pre[i-1]+b[i];
	for(int i=1;i<=n;i++)
	{
		int r=i,l=r+1-len,delta=b[i];
		int tmp=sum(l,r,delta);
		while(-(tmp+(b[l-1]-delta))<=m&&l>1)
		{
			tmp+=b[l-1]-delta;
			l--;
			len=max(len,r-l+1); 
		}
		//printf("i:%d l:%d r:%d delta:%d tmp:%d len:%d\n",i,l,r,delta,tmp,len);
	}
	printf("%lld",len);
	return 0;
}
