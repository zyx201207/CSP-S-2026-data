#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int arr[N];
int ans=0x3f3f3f;
bool flag=false;
bool cmp (int a,int b)
{
	return a>b;
};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(arr[i]%2==0)
		{
			flag=true;
		}
		break;
	}
	if(!flag)
	{
		for(int i=1;i<=m;i++)
		{
			ans=min(ans,arr[i]);
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(arr[i]%2==0)
			{
				ans=min(ans,arr[i]);
			}
		}
	}
	cout<<ans;
	return 0;
}

