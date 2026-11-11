#include<bits/stdc++.h>
using namespace std;
long long a[500002],n,m,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long t=a[2]-a[1];
	while(m>0)
	{
		cnt++;
		m-=cnt*t;
	}
	cout<<cnt;
	return 0;
}
