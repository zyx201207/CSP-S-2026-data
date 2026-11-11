#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int c,cnt,shu;
	c=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if(m<shu)
		{
			break;
		}
		cnt++;
		shu+=i*c;
	}
	cout<<cnt;
	return 0;
}
