#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e5+10
#define ld long long
long long a[50000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long cha=1000000000010,cha1=1000000000010;
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if (n==1)
	{
		printf("1");
		return 0;
	} 
	sort(a+1,a+n+1);
	long long a1=1;
	for (long long i=1;i<=n-1;i++)
	{
		if (a[i+1]-a[i]<=cha)
		{
			if (a[i]-a[i-1]<=cha1 && i-1>=1)
			{
				cha=a[i+1]-a[i];
				cha1=a[i]-a[i-1];
				a1=i+1;
			}
		} 
	}
	int res=1;
	long long l=a1-1,r=a1+1;
	long long zc,yc; 
	while (m>=0)
	{
	 	yc=a[r]-a[a1];
	 	zc=a[a1]-a[l];
	 	if (zc>yc)
	 	{
	 		if (r<=n)
	 		{
	 			m-=yc;
				res++;
				r++;
			}
			else
			{
				if (l<1)
				{
					printf("%lld",res);
					return 0;
				}
				m-=zc;
				res++;
				l--;
			}
		}
		else 
		{
			if (l>=1)
			{
				m-=zc;
				res++;
				l--;
			}
			else
			{
				if (r>n)
				{
					printf("%lld",res);
					return 0;
				} 
				m-=yc;
				res++;
				r++;
			}
		}
	}
	if (m<0)
	{
		res--;
	}
	printf("%d",res);
	return 0;
}

