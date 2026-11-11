/*
crystal subway migrate hub
14:30~18:30
long long!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=5e5+7;
int n;
ll m,a[N],s[N];
inline ll f(int l,int k)
{
	return 1ll*(k-l+1ll)*a[k]-(s[k]-s[l-1]);
}
inline int getl(int k)  //l尽可能往左边 
{
	int l=1,r=k;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(f(mid,k)<=m) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int k=1;k<=n;k++)
	{
		int l=getl(k);
//		cerr<<l<<' '<<k<<' '<<f(l,k)<<'\n';
		ans=max(ans,k-l+1);
	}
	cout<<ans;
	cout.flush();
	return 0;
}
/*
不难发现答案具有单调性
首先从小到大排序 
考虑钦定某一个元素a[k]，最终都变成这个元素
不用二分？？？ 
 
test4没过，偏小 
hack:
6 1
2 2 3 3 3 3

需要从k往前找一段，让这一段全部变成a[k] 
需要二分 
 
这个题很简单，*1000吧 
14:57过大样例 
*/
