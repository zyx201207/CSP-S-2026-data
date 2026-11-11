#include<bits/stdc++.h>
using namespace std;
int Answer[300010];
int Data[500010];
int Temp[500010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)scanf("%d",&Data[i]);
	for(int i=N;i>=1;i--)
	{
		for(int j=1;j<=N;j++)Temp[j]=Data[j];
		int Now=-1;
		for(int j=N-i+1;j<=N;j++)
		{
			if(Temp[j]==0)continue;
			else if(Temp[j]==-1)
			{
				Temp[j]=-114514;
				continue;
			}
			else if(Temp[j-1]==0&&j-1>0&&Temp[j]!=-1)
			{
				Temp[j]=0;
				continue;
			}
			for(int k=j+1;k<=N;k++)if(Temp[j]>0&&Temp[k]>0&&Temp[j]==Temp[k])
			{
				Temp[j+1]=0,Temp[k]=-1;
				break;
			}
		}
		for(int j=N-i+1;j<=N;j++)
		{
			if(Temp[j]!=0&&Temp[j]!=-114514)Answer[Temp[j]]++;
		}
	}
	for(int i=1;i<=M;i++)printf("%d ",Answer[i]);
	return 0;
}
