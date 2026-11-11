#include <iostream>

using namespace std;

long long C,T,n,d,x[2000010],f[5010][5010],s[5010][5010],cnt;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cnt=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>x[i];
		for(long long i=1;i<=n;i++)
		{
			for(long long j=0;j<=n;j++)f[i][j]=s[i][j]=s[i-1][j]=0;
			f[i][0]=s[i][0]=1;
			for(long long j=i+1,l=i;j<=n;j++)
			{
				while(x[j]-x[l]>d)l++;
				f[j][0]=0;
				s[j][0]=s[j-1][0];
				bool flg=1;
				for(long long k=1;k<=n;k++)
				{
					if(l==j)f[j][k]=0;
					f[j][k]=s[j-1][k-1]-s[l-1][k-1];
					s[j][k]=s[j-1][k]+f[j][k];
					if(flg&&f[j][k]==2)
					{
						//cerr<<"|"<<i<<" "<<j<<endl;
						cnt++;
					}
					if(f[j][k])flg=0;
				}
			}
		}
		cout<<cnt<<endl; 
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
