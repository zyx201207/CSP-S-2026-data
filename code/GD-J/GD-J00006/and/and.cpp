#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
const int M=31;
int n,m,now;
long long a[N],ans;
long long cnt[M][N],sum[M];
bool f[N];
int main()	{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	{
		cin>>a[i];
		f[i] =1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	{
		for(int j=29;j>=0;j--)	{
			if(a[i]&(1LL<<j))	cnt[j][i]++;
		}
	}
	for(int i=0;i<=29;i++)	{
		for(int j=1;j<=n;j++)	sum[i] += cnt[i][j];
	}
	for(int i=29;i>=0;i--)	{
		if(sum[i])	{
			now =i;
			break;
		}
	}
	int per =1;
	for(int i=now;i>=0;i--)	{
		int lp=0;
		for(int j=per;j<=n;j++)	{
			if(f[j])	lp+=cnt[i][j];
		}
		if(lp>=m)	{
			ans += (1LL<<i);
			for(int j=per;j<=n;j++)	{
				if(!cnt[i][j])	f[j]=0;
			}
			int h=per;
			for(int j=h;j<=n;j++)	{
				if(cnt[i][j])	{
					per=j;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
Trick||Treat!
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
