#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
			t+=min(a[l],a[r]);
		if(a[l]<a[r])
			a[r]-=a[l++];
		else if(a[l]>a[r])
			a[l]-=a[r--];
		else
		{
			l++;
			r--;
		}
	}
	cout<<t;
	return 0;
}

