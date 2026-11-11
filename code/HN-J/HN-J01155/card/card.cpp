#include <bits/stdc++.h>
using namespace std;
int n,m;
double num = 0.1;
int a[100005];//元素 
int b[100005];//牌堆 
int c[100005];//bool 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	for (int i = 1;i <= n;i++)//范围 
	{
		for (int j = i;j <= n;j++)//遍历范围中的元素 
		{
			if (c[a[j]] == 0)
			{
				num *= 10;
				b += a[j];
				c[a[j] - '0'] = 1;
			}
			else
			{
				for (int k = i;k <= j;k++)//查找该元素
				{
					if(b[k] == a[j])
					{
						erase(k,b.size() - k);
					} 
				} 
				 
			}
		}
	}
    
	return 0;
} 
