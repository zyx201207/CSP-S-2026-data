//GZ-S00038 贵阳市白云区华师一学校 林乾翔 
//我们发现肯定是选择序列内的数更优
//所以我们可以排序之后枚举每一个序列内的数
//从小往大递推将前i个数转化为a_i的代价
//然后找最后一个<=m的
//14：40 
//不好这个是假的
//换一种想法？
//我们发现只要我们确定了一个值作为目标
//哦哦是这样的
//我们考虑找一个离已经敲定了的a_i不远的数
//然后我们发现代价单调
//可以二分。注意要用map搞一下 
//好像不用二分，双指针即可 
//请将我挂上迷惑行为大赏 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=1,a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,pri=0;
	for(;r<=n;r++)
	{
		pri+=(a[r]-a[r-1])*(r-l);
		while(pri>m) pri-=(a[r]-a[l++]);
		ans=max(ans,r-l+1);
	} 
	cout<<ans;
	return 0;
}
//CSP-S 2026 rp++
//管理好时间
//记得打暴力
//今年能一等！！！
//相信自己。
//注意溢出和边界问题
//先把分拿完，然后手造样例过
//相信数据强度
//写对拍 
