#include <bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int n,m;
int a[N];
int tmp[N];
int ans[M];
void solve1()
{
	for(int k=1;k<=n;k++) // 遍历游戏 
	{
		// 处理游戏
		int cnt=0;
		for(int i=k;i<=n;i++)
		{
			tmp[++cnt]=a[i];
			for(int j=1;j<=cnt;j++)
			{
				if(tmp[cnt]==tmp[j])
				{
					cnt=j;
					break;
				}
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			ans[tmp[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
//int re[M];
//void solve2()
//{
//	for(int k=1;k<=n;k++) // 遍历游戏 
//	{
//		// 处理游戏
//		int cnt=0;
//		for(int i=0;i<=m;i++)
//		{
//			re[i]=0;
//		}
//		for(int i=k;i<=n;i++)
//		{
//			if(re[a[i]]!=0)
//			{
//				cnt=re[a[i]];
////				tmp[cnt]=a[i];
//			}
//			else
//			{
//				tmp[++cnt]=a[i];
//				re[a[i]]=cnt;
//			}
//		}
//		for(int i=1;i<=cnt;i++)
//		{
//			ans[tmp[i]]++;
//		}
//	}
//	for(int i=1;i<=m;i++)
//	{
//		cout<<ans[i]<<" ";
//	}
//	cout<<endl;
//}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	solve1();
//	solve2();
	return 0;
}
