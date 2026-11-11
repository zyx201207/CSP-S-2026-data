#include <bits/stdc++.h>
using namespace std;
const long long N=1e5*2+10;
struct node{
	long long s;
	char ch;
}a[N];
long long ans;
long long n;
long long jl=-1;
long long st=-1;
long long mid;
//long long sum[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i].s,&a[i].ch);
		//sum[i]=sum[i-1]+a[i].s;
	}
	
//	if(sum[n]%2==0)
//	{
//		mid=sum[n]/2;
//	}
//	else
//	{
//		mid=(sum[n]+1)/2;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(sum[i]==mid)
//		{
//			jl=i;
//			break;
//		}
//		if(sum[i]<jl && jl<sum[i+1])
//		{
//			st=i+1,jl=i;
//			break;
//		}
//	}
	//printf("%d %d\n",st,jl);
	long long cha=0;
	int j=n;
	for(int i=1;i<=j;i++)
	{
			if(cha>0)
			{
			if(a[i-1].ch==a[j].ch)
			{ 
				if(a[j].s>=cha)		a[j].s-=cha,cha=0;
				else if(a[j].s<cha)
				{
					cha-=a[j].s;
					a[j].s=0;
					j++;
				}
			}
			else
			{
				if(a[j].s>=cha)
				{
					a[j].s-=cha;
					ans+=cha;
					cha=0;
				}
				else if(a[j].s<cha)
				{
					ans+=a[j].s;
					a[j].s=0;
					j++;
					cha-=a[j].s;
				}
				
			}
		}
		if(cha<0)
		{
			if(a[i].ch==a[j-1].ch)
				{
				if(a[i].s>=cha)		a[i].s+=cha,cha=0;
				else if(a[i].s<abs(cha))
				{
					cha+=a[i].s;
					a[j].s=0;
					i++;
				}
			}
			else
			{
				if(a[i].s>=cha)
				{
					a[i].s+=cha;
					ans-=cha;
					cha=0;
				}
				else if(a[i].s<cha)
				{
					ans+=a[i].s;
					a[i].s=0;
					i++;
					cha+=a[i].s;
				}
			}
		}
		if(a[i].ch==a[j].ch)
		{
			if(a[i].s>a[j].s)
			{
				cha=a[i].s-a[j].s;
			}
			if(a[i].s==a[j].s)
			{
				cha=0;
			}
			if(a[i].s<a[j].s)
			{
				cha=a[i].s-a[j].s;
			}
		}
		else
		{
			if(a[i].s>a[j].s)
			{
				cha=a[i].s-a[j].s;
			}
			if(a[i].s==a[j].s)
			{
				cha=0;
			}
			if(a[i].s<a[j].s)
			{
				cha=a[i].s-a[j].s;
			}
			ans+=min(a[i].s,a[j].s);
		}
		j--;
		//printf("%lld %lld\n %lld",a[i].s,a[j].s,ans);
		//printf("%d\n",ans);
	}
	printf("%lld",ans);
	return 0;
}
