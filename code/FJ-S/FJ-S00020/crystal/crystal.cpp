/*
FJ-S00020 :)
rp+=1000000000
score=400
ccf ccf ccf ccf ccf ccf ccf ccf ccf
feropen()
freopen(".in","w",stdin)
freopen(".in","r",stdout)
freopen(".out","r",stdout)
freopen(".out","w",stdin)
freopen("1.in","r",stdin)
freopen("1.out","w",stdout)
freopen("2.in","r",stdin)
freopen("2.out","w",stdout)
int mian()
long long main()
main main main main main main main main main main 
bu yao jing mi huo ying wei da shang
2  4   4    2  4   2    2   4  3
bu yao jing mi huo ying wei da shang
2  4   4    2  4   2    2   4  3
bu yao jing mi huo ying wei da shang
2  4   4    2  4   2    2   4  3
bu yao jing mi huo ying wei da shang
2  4   4    2  4   2    2   4  3
bu yao jing mi huo ying wei da shang
2  4   4    2  4   2    2   4  3
luogu id:liuhuayang
bie guan zhu wo!
2   1    4   3
bie gei wo bao ling QAQ
2   2   3  4   2
*/
//T1 nlogn 100
//QAQ bie gua le a
/*
jin tian jin ran mei you jiao hu! 
1   1    4   2   2   3   2    4
pts:100+100+56+15=271
heng ke neng hui gua fen QAQ
3    3  2    4   4   1
xi wang bu yao gua fen!
1  4    2  4   4   4
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N],m;
int n;
bool chk(int mid)
{
	for(int i=1;i<=n-mid+1;i++)
	{
		int j=i+mid-1;
		long long s=1ll*mid*a[j]-sum[j]+sum[i-1];
		if(s<=m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
//	chk(3); 
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int m=(l+r)/2;
		if(chk(m))
		{
			ans=m;
			l=m+1;
		}else
		{
			r=m-1;
		}
	}
	cout<<ans;
	return 0;
}
