#include<bits/stdc++.h>
using namespace std;
bool b[30001];
//这波得寄啊11:10 
/*
4 3
1 2 1 3
*/
/*
  CCCCC     CCCCC   FFFFFFF
 CCCCCC    CCCCCC   FFFFFFF
CCCC      CCCC      FF
CC       CC         FF
CC       CC         FFFFFF
CC       CC         FFFFFF
CC       CC         FF
CCCC      CCCC      FF
 CCCCCC    CCCCCC   FF
  CCCCC     CCCCC   FF
*/
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1],c[30001]={0};
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]])
			{
				c[++t]=a[j];
				b[a[j]]=1;
			}
			else
			{
				for(int k=1;k<=t;k++)
					cout<<c[k];
				cout<<endl;
			}
		}
		/*for(int j=1;j<=n;j++)
			cout<<b[a[j]];
		cout<<endl;*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
emm,所以会上迷惑行为吗 
rp++;
++rp;
while(1)rp++;
*/

