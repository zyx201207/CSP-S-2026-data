#include<bits/stdc++.h>
using namespace std;
long long SumF[200010],SumS[200010];
int Cnt[200010];
char S[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>Cnt[i]>>S[i];
		SumF[i]=SumF[i-1]+Cnt[i];
	}
	for(int i=N;i>=1;i--)SumS[i]=SumS[i+1]+Cnt[i];
	long long Len=SumF[N],Answer=0;
	int NowF=1,NowS=N;
	for(long long i=1;i<=(Len>>1);i++)
	{
		if(i>SumF[NowF])NowF++;
		if(i>SumS[NowS])NowS--;
		if(S[NowF]!=S[NowS])Answer++;
	}
	cout<<Answer;
	return 0;
}
