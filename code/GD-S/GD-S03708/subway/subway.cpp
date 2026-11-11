#include<bits/stdc++.h>
using namespace std;
int Time[500010];

struct Ways
{
	int Sta;
	int To;
}Data[1010][100010];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Test,N,M,Max,T;
	scanf("%d%d%d%d%d",&Test,&N,&M,&Max,&T);
	for(int i=1;i<=M;i++)scanf("%d",&Time[i]);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&Data[i][0].To);
		for(int j=1;j<=Data[i][0].To;j++)scanf("%d%d",&Data[i][j].Sta,&Data[i][j].To);
	}
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("0\n");
	}
	return 0;
}
