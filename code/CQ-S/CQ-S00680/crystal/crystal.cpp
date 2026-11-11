#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],b[N],ans,sum,l,r,mid,x,y,o;
/*
inline int check(int l,int r,int k,int X)
{
	int mid,op = k;
	while(l <= r)//这里是找一个后缀 
	{
		mid = ((l+r)>>1);
		if(a[k]-a[mid] <= X) op = mid,r = mid-1;
		else l = mid+1;
	}
	return op;
}*/
/*
inline int check1(int l,int r,int k,int X)
{
	int mid,op = k;
	while(l <= r)//前缀
	{
		mid = ((l+r)>>1);
		if(a[mid]-a[k] <= X) op = mid,l = mid+1;
		else r = mid-1;
	}
	return op;
}*/
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++) b[i] = b[i-1]+a[i];
	for(int i = 1;i <= n;i++)
	{
		l = 0,r = i; o = i;
		while(l <= r) 
		{
			mid = ((l+r)>>1);
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1]) <= m) o = mid,r = mid-1;
			else l = mid+1;
		}
		ans = max(ans,i-o+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
有个很好的办法，就是直接钦定最后是哪一个
然后直接二分，找到第一次使得花费<=m即可 
哦哦看错题了，只能+1我去变简单了
没这么麻烦，直接二分即可
没啥问题先不管了 
*/
