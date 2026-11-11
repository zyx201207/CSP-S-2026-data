#include <bits/stdc++.h>
using namespace std;
const int maxn = 5*10e5+10;
int a[maxn];
int cnt[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n,m;
	int cnt1 = 1;
	cin>>n>>m;
	for(int i = 1 ; i <= n ;i++ )
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int mid = (n+1)/2;
	if(a[1]+1==a[2]&&a[2]+1==a[3])
	{
		
		for(int i =1 ; i <= n ;i++)
		{
			if(m >= i)
			{
			m-=i;
			cnt1++;
			}
		
		}
	
	}
	
	else if(a[3]-a[2]==a[2]-a[1])
	{
		int x=a[2]-a[1];
		while(m>=x)
		{
			m-=x;
			cnt1++;
		}
		
	}
	else
	{
		for(int i =n ; i>=1;i-- )
		{
		for(int j =i-1 ; j >=1;j--)
		{
		if(m>=a[i]-a[j])
		{
			m=m-(a[i]-a[i]);
		    cnt[i]++;
		}
		cnt1=max(cnt1,cnt[i]);
		}

		
	
	}
//	for(int i = mid+1 ;i <= n ;i++)
//	{
//		if((a[i]-a[mid])*mid>m)
//		{
//			break;
//		}
//		if((a[i]-a[i-1])*mid<=m)
//	{
//		m=m-((a[i]-a[i-1])*mid);
//		cnt++;
//	}
//	}
	}
	
	
	
	
	cout<<min(cnt1+1,n);
	
	
	return 0;
}
