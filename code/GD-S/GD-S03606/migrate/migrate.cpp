#include<bits/stdc++.h>
using namespace std;
long long C,T;
long long N;
long long D;
long long X[50005];
long long Ts[500005];
long long Ans[5005][5005][2];
long long sumAns;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--)
	{
		sumAns=0;
		scanf("%lld%lld",&N,&D);
		for(int i=1;i<=N;i++)
		{
			scanf("%lld",&X[i]);
		}
		long long g=1;
		for(int i=1;i<=N;i++)
		{
//			cout<<i<<" "<<g<<" "<<X[g]<<" "<<X[i]<<endl;
			while(X[g]-X[i]<=D&&g<=N)
			{
				g++;
			}
			Ts[i]=g-1;
		}
		for(int i=1;i<=N;i++)
		{
			Ans[N][i][0]=2100000000;
			Ans[N][i][1]=0;
		}
		Ans[N][N][0]=0;
		Ans[N][N][1]=1;
		for(int i=N-1;i>=1;i--)
		{
//			cout<<Ts[i]<<endl;
			for(int j=1;j<=N;j++)
			{
				Ans[i][j][0]=2100000000;
				Ans[i][j][1]=0;
			}
			Ans[i][i][0]=0;
			Ans[i][i][1]=1;
			if(Ts[i]==i)
			{
				Ans[i][i][0]=0;
				Ans[i][i][1]=1;
				continue;
			}
			if(Ts[i]==i+1)
			{
				for(int j=i+1;j<=N;j++)
				{
					Ans[i][j][0]=Ans[i+1][j][0]+1;
					Ans[i][j][1]=Ans[i+1][j][1];
					if(Ans[i][j][1]==2&&i!=j)
					{
						sumAns++;
					}
				}
				Ans[i][i][0]=0;
				Ans[i][i][1]=1;
				continue;
			}
			if(Ts[i]==i+2)
			{
				for(int j=1;j<=N;j++)
				{
					Ans[i][j][0]=Ans[i+2][j][0]+1;
					Ans[i][j][1]=Ans[i+2][j][1];
				}
				for(int j=1;j<=N;j++)
				{
				if(Ans[i+1][j][0]+1<Ans[i][j][0])
				{
					Ans[i][j][0]=Ans[i+1][j][0]+1;
					Ans[i][j][1]=Ans[i+1][j][1];
				}
				else if(Ans[i+1][j][0]+1==Ans[i][j][0])
				{
					Ans[i][j][1]+=Ans[i+1][j][1];
				}
				}
				for(int j=i+1;j<=N;j++)
				{
					if(Ans[i][j][1]==2)
					{
						sumAns++;
					}
				}
				for(int j=1;j<=N;j++)
				{
					Ans[i][j][1]=min(Ans[i][j][1],3ll);
				}
				Ans[i][i][0]=0;
				Ans[i][i][1]=1;
				continue;
			}
			for(int j=1;j<=N;j++)
			{
				if(Ans[Ts[i]][j][0]+1<Ans[i][j][0])
				{
					Ans[i][j][0]=Ans[Ts[i]][j][0]+1;
					Ans[i][j][1]=Ans[Ts[i]][j][1];
				}
				else if(Ans[Ts[i]][j][0]+1==Ans[i][j][0])
				{
					Ans[i][j][1]+=Ans[Ts[i]][j][1];
				}
			}
			for(int j=1;j<=N;j++)
			{
				if(Ans[Ts[i]-1][j][0]+1<Ans[i][j][0])
				{
					Ans[i][j][0]=Ans[Ts[i]-1][j][0]+1;
					Ans[i][j][1]=Ans[Ts[i]-1][j][1];
				}
				else if(Ans[Ts[i]-1][j][0]+1==Ans[i][j][0])
				{
					Ans[i][j][1]+=Ans[Ts[i]-1][j][1];
				}
			}
			for(int j=1;j<=N;j++)
			{
				if(Ans[Ts[i]-2][j][0]+1<Ans[i][j][0])
				{
					Ans[i][j][0]=Ans[Ts[i]-2][j][0]+1;
					Ans[i][j][1]=Ans[Ts[i]-2][j][1];
				}
				else if(Ans[Ts[i]-2][j][0]+1==Ans[i][j][0])
				{
					Ans[i][j][1]+=Ans[Ts[i]-2][j][1];
				}
			}
			for(int j=i+1;j<=Ts[i];j++)
			{
				Ans[i][j][0]=1;
				Ans[i][j][1]=1;
			}
			for(int j=i+1;j<=N;j++)
			{
				if(Ans[i][j][0]>2100000000)
				{
					Ans[i][j][1]=0;
				}
				if(Ans[i][j][1]==2)
				{
					sumAns++;
				}
			}
			for(int j=1;j<=N;j++)
			{
				Ans[i][j][1]=min(Ans[i][j][1],3ll);
			}
		}
		printf("%lld\n",sumAns);
	}
}
