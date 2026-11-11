#include<bits/stdc++.h>
using namespace std;
const long long Base=1e12;
long long Data[500010];
map<long long,int>Map;
int Maybe[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int N;
	long long M;
	scanf("%d%lld",&N,&M);
	int Max=0,ID=0;
	bool Special=true;
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&Data[i]);
		if(i>=3&&Data[i]+Data[i-2]!=(Data[i-1]<<1))Special=false;
		else if(i>=2&&Data[i]==Data[i-1])Special=false;
		Map[Data[i]+Base]++;
		if(Map[Data[i]+Base]>=Max)
		{
			Max=Map[Data[i]+Base];
			ID=i;
		}
	}
	if(Special&&N>=2)
	{
		if(Data[2]>Data[1])
		{
			long long Answer=1;
			for(int i=1;i<=N-1;i++)if(M>=i*(Data[i+1]-Data[i]))
			{
				M-=i*(Data[i+1]-Data[i]);
				Answer=i+1;
			}
			printf("%lld",Answer);
		}
		else
		{
			long long Answer=1;
			for(int i=N;i>=2;i--)if(M>=(N-i+1)*(Data[i-1]-Data[i]))
			{
				M-=i*(Data[i-1]-Data[i]);
				Answer=N-i+2;
			}
			printf("%lld",Answer);
		}
		return 0;
	}
	int Cnt=1;
	for(int i=ID+1;i<=N;i++)if(Data[i]<=Data[ID])
	{
		Maybe[Cnt++]=abs(Data[ID]-Data[i]);
	}
	for(int i=1;i<=ID-1;i++)if(Data[i]<=Data[ID])
	{
		Maybe[Cnt++]=abs(Data[ID]-Data[i]);
	}
	sort(Maybe+1,Maybe+1+Cnt);
	int i=0;
	while(i<Cnt&&M-Maybe[i]>=0)
	{
		M-=Maybe[i];
		i++;
	}
	printf("%d",i);
	return 0;
}
