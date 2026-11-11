#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[200010],res=LLONG_MAX;
bool flag[200010];
int main()
{
	memset(flag,true,sizeof flag);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(LL i=1ll<<30;i>=1;i>>=1)
	{
//		cout<<log2(i)<<": ";
//		for(LL j=1;j<=n;j++)
//			cout<<flag[j];
//		putchar('\n');
		int cnt=0;
		for(LL j=1;j<=n;j++)
		{
			if(((a[j]&i)!=0ll)&&flag[j])
			{
//				cout<<"Find j="<<j<<" a[j]="<<a[j]<<"=>"<<(a[j]&i)<<"\n";
				cnt++;
			}
		}
		if(cnt<m)
			continue;
		for(LL j=1;j<=n;j++)
		{
			if((a[j]&i)==0ll)
				flag[j]=false;
		}
	}
	for(LL i=1,j=1;i<=n&&j<=m;i++)
	{
		if(flag[i])
		{
			res&=a[i];
			j++;
		}
	}
	printf("%lld",res);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/

