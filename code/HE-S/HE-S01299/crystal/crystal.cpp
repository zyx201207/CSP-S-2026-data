#include<bits/stdc++.h>
using namespace std;
int n;//水晶数 
long long m;//操作次数
long long a[500005];//水晶
long long c[500005];//c[1]表示a[1]与a[2]的距离
long long ans;//可以使用的水晶数 
//定义函数求x-y需要多少能量
int e(int x,int y)
{
	int need = 0;//需要的能量
	for(int i = x;i < y;i ++)
	{
		need += a[y] - a[i];
	} 
	//将x - y-1的数变成了y
	return need; 
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	//输入
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i]; 
	} 
	//排序
	sort(a + 1,a + 1 + n);
	//求差值
	for(int i = 2;i <= n;i ++)
	{
		c[i - 1] = a[i] - a[i - 1];
	} 
	//滑动窗口 
	int l = 1,r = n; 
	while(l <= r)
	{
		//判断是否能填满 
		if(e(l,r) > m)
		{
			if(c[l] > c[r - 1])
			{
				l ++;
			}
			else
			{
				r --;
			}
			continue;
		}
		//得到一个可行数据范围
		ans = r - l + 1;
		break;
	}
	l = 1,r = n;
	while(l <= r)
	{
		//判断是否能填满 
		if(e(l,r) > m)
		{
			if(c[l] >= c[r - 1])
			{
				l ++;
			}
			else
			{
				r --;
			}
			continue;
		}
		//得到一个可行数据范围
		long long ans2 = r - l + 1;
		ans = max(ans,ans2);
		break; 
	}
	cout << ans;
	return 0;
	//保存时解注释	
}
