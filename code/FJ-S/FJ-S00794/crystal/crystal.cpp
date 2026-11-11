#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int op=abs(a[1]-a[2]);
	if(op==1)
	{
		int cnt=0;
		for(int i=1;i<=99999999;i++)
		{
			if(cnt>=m)
			{
				if(cnt==m)cout<<i;
				else cout<<i-1;
				break;
			}
			else cnt+=i;
		}
	}
	else
	{
		int cnt=0;
		for(int i=1;i<=99999999;i++)
		{
			if(cnt*2>=m)
			{
				if(cnt*2>m)cout<<i-2;
				else cout<<i;
				break;
			}
			else cnt+=i;
		}
	}
	return 0;
} 
