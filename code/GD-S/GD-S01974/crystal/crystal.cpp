#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int n,m; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long gongcha=a[2]-a[1];
	bool f=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=gongcha)
		{
			f=false;
			break;
		}
	}
	if(f==true)
	{
//		cout<<gongcha<<" ";
		long long temp=0;
		long long num=0;
		while(temp<m)
		{
			temp+=temp+gongcha;
			num++;
		}
		cout<<num;
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	long long maxn=LLONG_MIN;
	for(int i=1;i<=n;i++)
	{
		long long j=0;
		while((i*a[i])-(b[i]-b[j])>m)j++;
		maxn=max(maxn,i-j);
	}
	cout<<maxn;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
