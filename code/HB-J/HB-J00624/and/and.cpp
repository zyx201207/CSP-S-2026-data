#include <bits/stdc++.h>
using namespace std;
int n;
long long k,ans=0;
int as[31][2000]={};
int main()
{
    //freopen("and.in","r",stdin);                                          
    //freopen("and.out","w",stdout); 
    cin >>n;
    for (int i=1;i<=n;i++)
    {
		cin >>k;
	    for (int j=1;j<=9999;j++)
	    {
			if (k==0) break;
			int m=k%2;
			as[j][i]=m;
		}
	}
	for (int i=1;i<=n;i++)
	{
		long long kl=0;
		for (int j=i+1;j<=n;j++)
		{
			long long num=1;
			for(int p=1;p<=31;p++)
			{
				kl=kl+num*min(as[p][i],as[p][j]);
				num*=2;
			}
			ans=max(ans,kl);
		}
	}
	cout <<ans;
    return 0;
}
