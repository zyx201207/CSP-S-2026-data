#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
int n,maxx=INT_MIN,dp[M];
ll m,a[M],cha[M],pre[M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		cha[i]=abs(a[i]-a[i-1]);
	for(int i=2;i<=n;i++)
		pre[i]=pre[i-1]+cha[i];
	for(int i=1;i<=n;i++)
	{
		int j=i;
		ll x=m;
		while(j>=2&&x>0)
		{
			j--;
			x-=pre[i]-pre[j];
		}
		if(x<0)	j++;
		maxx=max(maxx,i-j+1);
	}
	cout<<maxx;
	return 0;
}
/*
	《这是一篇游记》
	好难啊，一题都ac不了，我是真没招了
	打打暴力跑路了好吧亲γβΔδηρα
*/ 
