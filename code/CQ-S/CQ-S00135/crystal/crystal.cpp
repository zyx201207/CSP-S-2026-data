#include<bits/stdc++.h> // 60 暴？力！ 
#define inf LLONG_MAX
#define ll long long 
#define maxn 500005
using namespace std;
ll l=inf,r=-inf;
ll a[maxn];
int n,m;
ll ans;
ll check(ll mid)
{
	vector<ll>x;
	for(int i=1;i<=n;i++)
		if(mid>=a[i])
			x.push_back(mid-a[i]);
	sort(x.begin(),x.end());
	ll ret=0;
	for(int i=0;i<x.size();i++)
	{
		if(ret+x[i]>m)
			return i;
		ret+=x[i];
	}
	return x.size();
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	//*	  60	（删除此处的一个下划线可更改注释掉的部分 
	for(ll i=l;i<=r;i++)
		ans=max(ans,check(i));
	/*/// 50	（为什么这种还要少10分呢……什么鬼部分分思路…… 
	for(ll i=1;i<=n;i++)
		ans=max(ans,check(a[i]));
	//*/
	cout<<ans;
	return 0;
}
/*

戏一折 水袖起落

唱悲欢 唱离合 无关我 

扇开合 ……

UID:1493649（应该大概也许可能差不多我记的是对的吧…… 

15:14 


18:18

希望我这代码给力点AwA

也许还能多拿点分呢…… 
 
*/
