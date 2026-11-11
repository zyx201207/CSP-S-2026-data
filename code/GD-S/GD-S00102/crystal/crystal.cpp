#include<bits/stdc++.h>
using namespace std;
const long long Ma=0x3f3f3f3f3f3f3f3f;

long long n,m,a[514514],ans,ansi;
long long bj,gc;

bool dc;

void pd()
{
	if(n==1)
	{
		dc=1;
	}
	else if(n==2)
	{
		dc=1,gc=a[2]-a[1];
	}
	else 
	{
		long long b=a[2]-a[1];
		for(int i=3;i<=n;i++)
		{
			if(a[i]-a[i-1]==b) bj++;
		}
		if(bj==n-2) dc=1,gc=b;
	}
	
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	pd(); //判断是否为等差数列
	
	if(dc==1)//特殊性质
	{
		long long mm=m;
		if(n==1) 
		{
			cout<<1;
			return 0;
		}
		else if(n==2)
		{
			if(gc>m) cout<<1;
			else cout<<2;
		}
		else
		{
			/*
			9 6
			1 3 5 7 9 11 13 15 17
			*/
			for(int i=n;i>=1;i--)
			{
				long long c=a[n]-a[i];
				if(mm<c) 
				{
					break;
				}
				ans++;
				mm-=c;
			}
			printf("%lld",ans);
		}
		return 0;
	}
	
	
	for(int i=a[1];i<=100000;i++){//暴力 
		long long t=0,mm=m,x=0;//x为A中>=I的起始点
		x=lower_bound(a+1,a+n+1,i)-a;
		if(x==-1) x=n+1;
		else for(int j=x+1;j<=n;j++)
			 	if(a[j]==i) x++;
				else break; 

		for(int j=x;j>=1;j--)
		{
			if(a[j]>i) break;
			long long c=i-a[j];
			if(c>mm) break; 
			t++;
			mm-=c;
		}
		
//		if(i==2)
//		{
//			cout<<x<<" "<<t<<" "<<m-mm<<endl;
//		}
		
		if(t>ans) ans=t,ansi=i;
	}
	printf("%lld",ans);
	//printf("\n凑%lld",ansi);
	return 0;
}//前缀和优化？
/*
5 5
1 2 4 8 9
凑4,ans=3 

5 8
-3 -1 2 2 7
凑2,ans=4

7 4
1 2 3 4 5 6 7
凑3,ans=3 

9 6
1 3 5 7 9 11 13 15 17
凑5,ans=3 
*/
