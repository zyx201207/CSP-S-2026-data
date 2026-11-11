#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,ans;
LL a[500005];
vector<LL>v;
bool check(int mid)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(mid>a[i]) cnt=cnt+mid-a[i];
	}
	return cnt==m;
}
LL findsame(int k)
{
	LL num=0;
	for(int i=1;i<=n;i++)
	{
		if(k>=a[i]) num++;
	}
	return num;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=a[1];i<=a[n];i++)
	{
		if(check(i))
		{
			LL num=findsame(i);
			ans=max(num,ans);
		}
	}
	cout<<ans;
	return 0;
}
