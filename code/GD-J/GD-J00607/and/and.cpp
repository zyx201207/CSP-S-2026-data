#include<bits/stdc++.h>
#define int unsigned long long
#define N 200010
using namespace std;
int n,m,a[N],ans=(-1>>1);
bool tmp[N][30]; //每个数每个位提供的贡献 
int tal[30];
inline void tob(int ps,int len,int i)
{
	if(ps==1) 
	{
		tal[len]+=ps%2,
		tmp[i][len++]=1;
	}
	else if(!ps) return;
	else 
	{
		tal[len]+=ps%2;
		tmp[i][len++]=ps%2;
		tob(ps/2,len,i);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tob(a[i],0,i);
	}
	for(int i=30;i>0;i--)
	{
		//找最高位没法使用的情况
		if(tal[i]<m)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]>=(1<<i)) a[j]-=(1<<i);
			}
		}
	}
	sort(a+1,a+n+1);
	while(m--)
	{
		ans&=a[n-m];
	}
	cout<<ans;
	return 0;
}
