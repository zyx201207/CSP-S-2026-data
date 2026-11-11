#include <bits/stdc++.h>
using namespace std;
int zhanQAQtai[600];
int taiQAQxianlu[510][25];
int q[1000];
int juli[1000];
int yangli,xianlu,zhan,zhanzuiduoxian,jihua;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>yangli>>xianlu>>zhan>>zhanzuiduoxian>>jihua;
    for(int i=1;i<=zhan;i++) cin>>zhanQAQtai[i];
    for(int i=1;i<=xianlu;i++)
    {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int bianhao;
			cin>>bianhao;
			cin>>taiQAQxianlu[bianhao][i];
		}
	}
	for(int i=1;i<=jihua;i++)
	{
		int qidian,zhongdian;
		cin>>qidian>>zhongdian;
		int head=0,tail=0;
		for(int j=1;j<=zhan;j++)
		{
			juli[j]=INT_MAX;
		}
		juli[qidian]=0;
		q[++tail]=qidian;
		while(head<tail)
		{
			head++;
			for(int j=1;j<=xianlu;j++)
			{
				if(taiQAQxianlu[q[head]][j]!=0)
				{
					for(int k=1;k<=zhan;k++)
					{
						if(taiQAQxianlu[k][j]!=0)
						{
							if(juli[q[head]]+taiQAQxianlu[q[head]][j]+taiQAQxianlu[k][j]<juli[k])
							{
								juli[k]=juli[q[head]]+taiQAQxianlu[q[head]][j]+taiQAQxianlu[k][j];
								q[++tail]=k;
							}
						}
					}
				}
			}
		}
		int ans=juli[zhongdian]+zhanQAQtai[qidian]+zhanQAQtai[zhongdian];
		cout<<ans;
		if(i!=jihua) cout<<'\n';
	}
    return 0;
}
