#include<bits/stdc++.h>
using namespace std;
int n,x;
char a1,a[900000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>a1;
		while(x--)
		{
			num++;
			a[num]=a1;
		}
	}
	int sum=0,ans=1,ans1=2,cnt=0;
	sum=num/2;
	for(int i=sum;i>=1;i--)
	{
		if(num%2==0)
		{
			if((int)a[i]!=(int)a[i+ans])
			{
				cnt++;
				ans+=2;
			}        
		}
		if(num%2!=0)
		{
			if((int)a[i]!=(int)a[i+ans1])
			{
				cnt++;
				ans1+=2;
			}
		}
	}
	cout<<cnt;
	return 0;
}
