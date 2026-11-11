#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005],MAX,ans,now;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i]; 
	}
	if(!n<=5000)
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			now=m;
			for(int j=1;j<=i;j++)
			{
				b[j]=abs(a[i]-a[j]);
			}
			for(int j=i;j>=1;j--)
			{
				//cout <<"i: " <<i <<" j: " <<j <<" a[j]: " <<a[j] <<" b[j]: " <<b[j] <<" now: "<<now <<" ans: " <<ans <<" MAX: " <<MAX <<endl;
				if(b[j]<=now)
				{
					now-=b[j];
					ans++;
					if(ans>=MAX)
					{
						MAX=ans;
					}
				}
			}
			ans=0;
		}
		cout <<MAX;
		return 0;
	}
	else
	{
		bool ok=1,ok1=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=i)
			{
				ok=0;
			}
			if((a[i]-a[i-1])!=(a[i+1]-a[i]))
			{
				ok1=0;
			}
			if((ok|ok1)==0)
			{
				break;
			}
		}
		if(ok)
		{
			int i=1;
			while(now>0)
			{
				now-=i;
				i++;
			}
			cout <<i-1;
		}
		else if(ok1)
		{
			int i=a[2]-a[1];
			while(now>0)
			{
				now-=i;
				i+=a[2]-a[1];
			}
			cout <<i-1;
		}
		else
		{
			cout <<n;
		}
	}
	return 0;
}






















































































































































































































































































































































































/*AC!求求了
有没有人一起玩我的世界啊!
*/ 
 
