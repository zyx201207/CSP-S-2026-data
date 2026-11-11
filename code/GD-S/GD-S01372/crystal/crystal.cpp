#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],s[N],m;int n;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		int sum=a[i]*x-(s[i]-s[i-x]);
		if(sum<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
/*
T1简单二分，T2跑一边floyd也过了，T3想了将近三个小时，只骗了32分。但总归是比去年71分好，个人感觉可以1=（1=线要是超过250出题人可以跳了） 
原本的466考场可能是电脑出问题了，集体搬迁至365和367（366去哪了），键盘和鼠标在电脑下面一个可以拉出来的抽屉里，还好我机智，扯了点线出来，放在了桌面上，打
字不用那么拧巴了（这个换行主要是cpp显示不下了）。 
14:45解决第一题 
15:16做完第二题 
15:26测试第二题极限数据，发现要用1.3s，就加上了快读和一些优化，压缩到了0.6s
16:01显示器炸了，是线没接好
17:05第三题想了半天的思路发现是错的，准备想暴力，发现暴力也不会 
18:11第三题打了一个O^3+特殊性质A的拼好分，期望32分，第四题算了，就剩十五分钟了 
18:14觉得第四题什么也不打不太合适，打了一个“不可以总司令”，期望0分 
18:19在T2写了一些空洞骑士，会不会有哪个迷惑行为打赏会看见？ 
18:24最后两分钟，没啥想写的，代码保存一下撤了吧，上午考的还不错，下午一般，期望232分。 
 


fishy祭天，法力无变 
*/
