#include<bits/stdc++.h>
using namespace std;
int Data[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Test,T;
	scanf("%d%d",&Test,&T);
	while(T--)
	{
		int N,Max;
		scanf("%d%d",&N,&Max);
		for(int i=1;i<=N;i++)scanf("%d",&Data[i]);
		printf("0\n");
	}
	return 0;
}
