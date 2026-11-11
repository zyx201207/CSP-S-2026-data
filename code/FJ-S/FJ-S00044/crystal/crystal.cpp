#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m;
ll a[N];
ll d[N];
//d[i]表示a[i]-a[i-1]
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	ll ans=0;
	ll l=1,sum=0;
	for(int r=1;r<=n;r++)
	{
		sum+=(r-l)*d[r];
		while(l<=r&&sum>m)
		{
			sum-=a[r]-a[l];
			l++;
		}
	//	cout<<l<<' '<<r<<' '<<sum<<'\n'; 
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5 
1 2 4 8 9

l=1

r:
1 
2 
3 
4 
5 

a[i-1]-a[j]+a[i-1]-a[j+1]+...+a[i-1]-a[j+2]+...+a[i-1]-a[i-1]

i-j


1 2 3 4 5 6


用于合成的水晶必须具有相同的能量值。
小R希望参与合成的水晶尽可能多
他可以进行.至.多m次操作。每次操作可以任选一颗水晶，将其能量值增加1；
同一颗水晶可以被重复选择。
最多能用多少颗能量水晶合成一颗大水晶。

可以将某一个元素增加x，求增加量<=m时的最大相同元素个数

sort

d[i]表示a[i]-a[i-1]




n<=5e5+5,m<=1e18

3

5 8
-3 -1 2 2 7


*/
