#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a[10005];
	int c[10005],n,b,cnt=0;
	long long s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		
		cin>>c[i]>>a[i];
		s+=c[i];
		
		
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			cnt++;
		}	
	}
	if(cnt==n-1||n==1)
	{
		cout<<0;
		return 0;
	}
	b=s/2;
	cout<<b;
	return 0;
}
