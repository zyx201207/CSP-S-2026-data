#include<bits/stdc++.h>
using namespace std;
int fast,slow,sum;
long long n,m,zw,w,qy=999999999999999,qyl,qyr,c,ans;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++)
	{ 
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	slow=0;
	fast=1;
	for(int i=0;i<n;i++)
	{
		w=0;
		for(int j=slow;j<=fast;j++)
		{
			w+=a[j];
			c=c+a[fast]-a[j];
			
		}
		zw=a[(fast-slow)/2];
		w=w/(a[fast]-a[slow]);
		if((qy>abs(w)||c<=m)&&fast!=slow)
		{
			qyl=slow;
			qyr=fast;
			qy=abs(w);
			fast++;
		}
		else
		{
			fast++;
			slow++;
		}
	}
	c=0;
	for(int i=qyr;i>=qyl;i--)
	{
		if(c<m)
		{
			c=c+a[qyr]-a[i];
		}
		if(c==m)
		{
			while(a[qyr]==a[qyr+1])
			{
				qyr++;
			}
			ans=qyr-i+1;
			printf("%lld", ans);
			break;
		}
		if(c>m)
		{
			while(a[qyr]==a[qyr+1])
			{
				qyr++;
			}
			ans=qyr-i;
			printf("%lld", ans);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5 
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
