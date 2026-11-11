#include <bits/stdc++.h>
using namespace std;
int a[999];
int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

int n,m;
cin>>n,m;
int cnt=0;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a+1,a+n+1);
int mid=n/2;
for(int i=1;i<=n;i++)
{
	

	while(a[i]!=mid)
	{
		a[i]++;
		cnt++;
		if(cnt==m)
		{
			break;
		}
		if(a[i]==mid)
		{
			break;
		}
	}
	
	if(cnt==m)
	{
		break;
	}
	if(a[i]==mid)
	{
		
		continue;
	}
}

int sum=0;
int y;
for(int p=1;p<=n;p++)
{
	 y=a[1];
	 if(a[p]==y)
	 {
	 	sum++;
	 }
}

cout<<sum;
	return 0;
}
