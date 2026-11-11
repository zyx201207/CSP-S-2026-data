#include<bits/stdc++.h>
using namespace std;
int c,t;//编号、组数
long long n,d;//岛屿数、一次性飞行距离
long long x[2000005]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	//输入t组数据
	scanf("%d%d",&c,&t);
	while(t --)
	{
		//输入岛屿数、一次性飞行距离
		scanf("%d%d",&n,&d);
		//输入岛屿距离
		for(int i = 1;i <= n;i ++)
		{
			cin >> x[i];
		} 
		//双径岛屿数
		long long ans = 0; 
		//遍历1~n，求出每个岛屿拥有的双径岛屿
		for(int i = 1;i <= n;i ++)
		{
			//在i的坐标基础上，加上d。
			//如果在它下一个岛屿与岛屿i 之间只有两个岛屿，它就是一个双径岛屿
			long long len = x[i] + d; 
			//开关，判断岛屿j是否合法 
			bool sw = false; 
			//求出len后的下一个岛屿
			int j;//岛屿编号 
			for(j = i;j <= n;j ++)
			{
				//判断是否是len的下一个岛屿 
				if(x[j] > len && x[j] - x[j - 1] <= d)
				{
					sw = true;
					//得到了len的下一个岛屿  
					break;	
				} 
			} 
			//寻找x[i]到x[j]之间的岛屿数
			int lan = 0;
			for(int z = 1;z <= n;z ++)
			{
				//判断是否在x[i]和x[j]之间
				if(x[z] > x[i] && x[z] < x[j])
				{
					lan ++;
				} 
				//优化
				if(lan > 2)
				{
					break;
				} 
			} 
			if(lan == 2 && sw == true)
			{
				ans ++;
			}
		} 
		cout << ans << endl;
	} 
	return 0;
	//保存时解注释	
}
