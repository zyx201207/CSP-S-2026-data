#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,maxx=0;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		while(a[i]*(i-l+1)-sum>m)
			sum-=a[l],l++;
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
}
