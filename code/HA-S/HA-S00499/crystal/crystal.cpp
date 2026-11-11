#include<bits/stdc++.h>
using namespace std;
bool sort1(int a,int b)
{
	return a>b;
}
bool sort2(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m,a[100005],cnt[100005],lgst=0,j=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,sort2);
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]==1)
		{
			cout<<((sqrt(1+8*m)-1)/2)+1;
			return 0;		
		}

	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<' ';
//	}
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]==a[i])
		{
			cnt[j]++;
			lgst=a[i];			
		}
		else
		{
			j++;
		}
	}
	sort(cnt,cnt+n,sort1);
//	for(int i=0;i<n;i++)
//	{
//		cout<<cnt[i]<<' ';
//	}
	cout<<cnt[0]+1;
	return 0;
}
