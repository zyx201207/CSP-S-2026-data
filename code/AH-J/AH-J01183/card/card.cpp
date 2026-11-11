#include <iostream>
#include <cstring>
using namespace std;
long long a[500005],b[300005],pd[300005],num[300005],sum[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			int x=n-i+1;
			num[1]+=(x%2);
		}

		cout << num[1];
	}
	for(int i=1;i<=n;i++)
	{
		memset(pd,0,sizeof(pd));
		for(int j=i;j<=n;j++)
		{
			if(pd[a[j]]!=0)
			{
				for(int k=pd[a[j]];k<=j;k++)
				{
					pd[a[k]]=0;
				}
			}
			else
			{
				pd[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			num[j]+=(pd[j]>0);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << num[i] << " ";
	}
}



























































































































































































































//感谢来自CCF的恩赐（划掉）部分分，至少100+100+70+0=270































//——————————————————————————————————————————————————————这是理论最高分————————————————————————————————————————————

































































































