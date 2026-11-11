#include<bits/stdc++.h>
using namespace std;
int Data[200010];
int _=0;
int N;

int Sum(int x)
{
	int Cnt=0;
	while(x)
	{
		Cnt+=x&1;
		x>>=1;
	}
	return Cnt;
}

void DFS(int ID,int Now,int M,bool Flag)
{
	if(M==0)
	{
		_=max(_,Now);
		return;
	}
	if(ID>N)return;
	else if(Flag)
	{
		if(Now==-1)Now=Data[ID];
		else Now&=Data[ID];
		M--;
	}
	DFS(ID+1,Now,M,true);
	DFS(ID+1,Now,M,false);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int M;
	scanf("%d%d",&N,&M);
	bool SpecialB=true;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&Data[i]);
		if(Data[i]!=i-1)SpecialB=false;
	}
	if(M==1)
	{
		printf("%d",Data[1]);
		return 0;
	}
	else if(M==2)
	{
		int Max=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)if(i!=j)
			{
				Max=max(Max,Data[i]&Data[j]);
			}
		}
		printf("%d",Max);
		return 0;
	}
	else if(M==N)
	{
		for(int i=1;i<=N-1;i++)Data[N]&=Data[i];
		printf("%d",Data[N]);
		return 0;
	}
	else if(SpecialB)
	{
		vector<pair<int,int> >Bit(N);
		for(int i=1;i<=N;i++)Bit[i-1]={Sum(Data[i]),Data[i]};
		sort(Bit.begin(),Bit.end(),greater<pair<int,int> >());
		int Answer=Bit[0].second;
		for(int i=1;i<M;i++)Answer&=Bit[i].second;
		printf("%d",Answer);
		return 0;
	}
	for(int i=1;i<=N-M+1;i++)
	{
		DFS(i,Data[i],M,true);
		DFS(i,-1,M,false);
	}
	printf("%d",_);
	return 0;
}
