#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll now=0;
	for(int j=31;j>=0;j--)
	{
		ll res=0;
		for(int i=1;i<=n;i++)
		{
			if((a[i]&now)==now)
			{
				if((a[i]>>j)&1)
				{
					res++;
				}
			} 
		}
		if(res>=m)
		{
			now|=(1<<j);
		}
	}
	cout<<now;
	return 0;
}
/*
从这n个非负整数中选出.恰.好m个，
使得选出的m个数的.二.进 .制 .按 .位 .与的值最大

n<=2e5+5


O(NlogN)

从大到小

now目前可凑出几位一的掩码

0011
1111
1100
1100


*/ 
