#include<bits/stdc++.h> 
using namespace std;
long long n,sum,sums,sumx;
struct node{
	char a1[1];
	long long num;
}a[200005];
struct node1{
	char a1[1];
	long long num,s1;
}b[200005];
struct node2{
	char a1[1];
	long long num,s1;
}c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].a1;
		sum+=a[i].num;
	}long long s=0;
	for(int i=1;i<=n;i++)
	{
		if(s+a[i].num>=sum/2)
		{
			b[i].a1[0]=a[i].a1[0];
			b[i].num=(sum/2)-s;
			b[i].s1=sum/2;
			sums++;
			break;
		}else
		{
			s+=a[i].num;
			b[i].a1[0]=a[i].a1[0];
			b[i].num=a[i].num;
			b[i].s1=s;
			sums++;
		}
	}s=sum;
	for(int i=n;i>=1;i--)
	{
		if(s-a[i].num<=sum/2)
		{
			c[n-i+1].s1=sum/2;
			sumx++;
			if(sum%2==0)
			{
				c[n-i+1].a1[0]=a[i].a1[0];
				c[n-i+1].num=s-sum/2;
			}else
			{
				c[n-i+1].a1[0]=a[i].a1[0];
				c[n-i+1].num=s-sum/2-1;
			}
		}else
		{
			s-=a[i].num;
			c[n-i+1].a1[0]=a[i].a1[0];
			c[n-i+1].num=a[i].num;
			c[n-i+1].s1=sum-s;
			sumx++;
		}
	}long long ss=0,bl=sum/2,xs1=1,xs2=1;
	while(bl)
	{
		if(b[xs1].num>c[xs2].num)
		{
			if(b[xs1].a1[0]!=c[xs2].a1[0])
			{
				ss+=c[xs2].num;
			}b[xs1].num-=c[xs2].num;
			
			bl-=c[xs2].num;xs2++;
		}else if(b[xs1].num<c[xs2].num)
		{
			if(b[xs1].a1[0]!=c[xs2].a1[0])
			{
				ss+=b[xs1].num;
			}c[xs2].num-=b[xs1].num;
			
			bl-=b[xs1].num;xs1++;
		}else
		{
			if(b[xs1].a1[0]!=c[xs2].a1[0])
			{
				ss+=b[xs1].num;
			}
			bl-=b[xs1].num;xs2++;
			xs1++;
		}
	}cout<<ss;
	return 0;
}
