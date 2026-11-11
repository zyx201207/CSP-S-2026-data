#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,flag=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]>m)flag++;
	}
	if(flag==n)
	{
		cout<<1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	int st=1,fnl;
	int ans=0,num=0;
	for(int i=1;i<=n;i++)
	{
		fnl=i;
		b[i]=b[i-1]+a[i];
		if((b[i]+m)/(fnl-st+1)>=a[i])
		{
			ans++;
			num=max(ans,num);
		}
		else 
		{
			if(st<i)
			{
				ans--;
				b[i-1]-=a[st];
				st++;
				i--;
			}
			else
			{
				st=i;
				b[i]=0;
				ans=0;
				i--;
				continue;
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
