#include<bits/stdc++.h> 
using namespace std;
const int N=50005;
stack <int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x[N],ji[N]={0};
	bool cnt[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++)
		{
			if(cnt[x[j]])
			{
				while(s.top()!=x[j])
				{
					s.pop();
				}
			}
			else
			{
				cnt[x[j]]=1;
				s.push(x[j]);
			}
		}
		while(!s.empty())
		{
			ji[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ji[i]<<" ";
	}
	return 0;
}
/*
计数排序？ 
nono,栈直接模拟48分
没看出来正解
100+68+50+48=266(前提是后两题暴力得打出来) 
先打t3 
完了t3爆0了
完了，好像不小心把t3正解打出来了
100+68+100+0=268 
不怼，样例5过了样例4没过
特殊性质b过不了，90最坏50
100+68+50+0=218
t3就这样了，打t4
还有12分钟，t4仍然0分 
还有9min找到一个bug 
除了样例1都是没输出 
//没了
218 1=没了 
*/
