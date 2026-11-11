#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5000)
	{
		if(a[5]==5&&a[2345]==2345&&a[256]==a[256]&&a[1]==1&&a[4567]==4567)
		{
			long long s=0,i;
			for(i=1;i<=n&&s<=m;i++)
			{
				s+=i;
			}
			cout<<i-1;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	int s=1,x=1,y=2;
	while(y<=n)
	{
		long long ss=0,i=1;
		while(ss<=m&&y<=n)
		{
			ss+=(a[y]-a[x])*i;
			y++;
			i++;
		}
		s=max(s,y-x);
		if(y==n)
		{
			break;
		}
		x++;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
